#!/usr/bin/env python3

encodings = [
  'windows-1250', 'windows-1251', 'windows-1252', 'windows-1253', 'windows-1254',
  'windows-1255',  'windows-1256', 'windows-1257', 'windows-1258',
  'iso-8859-1', 'iso-8859-2', 'iso-8859-3', 'iso-8859-4', 'iso-8859-5', 'iso-8859-6', 'iso-8859-7', 'iso-8859-8', 'iso-8859-9', 'iso-8859-10',
  'iso-8859-11', 'iso-8859-13', 'iso-8859-14', 'iso-8859-15', 'iso-8859-16'
  ]

with open('src/tutf8e.c', 'w') as src:

  src.write('''
#include <tutf8e.h>

#include <sys/errno.h>

/* Determine the input length and UTF8 encoded length of NUL-terminated input string */
/* return ENOENT if input character is not convertable                               */
/* return 0 for success                                                              */

int tutf8e_string_length(const uint16_t *table, const char *input, size_t *ilen, size_t *olen)
{
  for (const unsigned char *i = (const unsigned char *) input; *i; ++i, (*ilen)++) {
    const uint16_t c = table[*i];
    if (c<0x80) {
      *olen += 1;
      continue;
    }
    if (c<0x800) {
      *olen += 2;
      continue;
    }
    if (c<0xffff) {
      *olen += 3;
      continue;
    }
    return ENOENT;
  }
  return 0;
}

/* Determine the length of the UTF8 encoding of given input string and table */
/* return ENOENT if input character is not convertable                       */
/* return 0 for success                                                      */

int tutf8e_buffer_length(const uint16_t *table, const char *input, size_t ilen, size_t *length)
{
  for (const unsigned char *i = (const unsigned char *) input; ilen; ++i, --ilen) {
    const uint16_t c = table[*i];
    if (c<0x80) {
      ++*length;
      continue;
    }
    if (c<0x800) {
      *length += 2;
      continue;
    }
    if (c<0xffff) {
      *length += 3;
      continue;
    }
    return ENOENT;
  }
  return 0;
}

/* UTF8 encode the given input string and table        */
/* return E2BIG if output buffer insuficient           */
/* return ENOENT if input character is not convertable */
/* return 0 for success                                */

int tutf8e_buffer_encode(const uint16_t *table, const char *input, size_t ilen, char *output, size_t olen)
{
  unsigned char *o = (unsigned char *) output;
  for (const unsigned char *i = (const unsigned char *) input; ilen; ++i, --ilen) {
    const uint16_t c = table[*i];
    if (c<0x80) {
      if (olen<1) return E2BIG;
      *(o++) = c;
      olen -= 1;
      continue;
    }
    if (c<0x800) {
      if (olen<2) return E2BIG;
      *(o++) = 0xc0 | (c>>6);
      *(o++) = 0x80 | (c&0x3f);
      olen -= 2;
      continue;
    }
    if (c<0xffff) {
      if (olen<3) return E2BIG;
      *(o++) = 0xe0 | (c>>12);
      *(o++) = 0x80 | ((c>>6)&0x3f);
      *(o++) = 0x80 | (c&0x3f);
      olen -= 3;
      continue;
    }
    return ENOENT;
  }
  return 0;
}
''')

with open('include/tutf8e.h', 'w') as include:

  include.write('''
#ifndef TUTF8E_H
#define TUTF8E_H

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

/* Internal API */
extern int tutf8e_string_length(const uint16_t *table, const char *i, size_t *ilen, size_t *olen);
extern int tutf8e_buffer_length(const uint16_t *table, const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_encode(const uint16_t *table, const char *i, size_t ilen, char *output, size_t olen);

/* External API */
''')

  include.write('\n/* Encode NUL-terminated string to UTF8 */\n')
  for e in sorted(encodings):
    name = e.replace('-', '_').lower()
    include.write('extern int % -33s(char *output, size_t olen, const char *input);\n'%('tutf8e_string_encode_%s'%(name)))

  include.write('\n/* Encode NUL-terminated string to UTF8, realloc as necessary */\n')
  for e in sorted(encodings):
    name = e.replace('-', '_').lower()
    include.write('extern char * % -33s(char *input);\n'%('tutf8e_string_encode_%s_realloc'%(name)))

  include.write('\n/* Encode buffer to UTF8 */\n')
  for e in sorted(encodings):
    name = e.replace('-', '_').lower()
    include.write('extern int % -33s(char *output, size_t olen, const char *input, size_t ilen);\n'%('tutf8e_buffer_encode_%s'%(name)))

  for e in sorted(encodings):

    mapping  = {}
    domain   = []

    name = e.replace('-', '_').lower()

    print('Encoding: %s'%(e))

#   include.write('\n/* %s */\n'%(e))
#   include.write('extern char * encode_%s_to_utf8(const char *input);\n'%(name))
#   include.write('extern int % -33s(char *output, size_t olen, const char *input);\n'%('tutf8e_string_encode_%s'%(name)))

    with open('src/%s.c'%(name), 'w') as src:

      # Emit code

      src.write('#include <tutf8e.h>\n')
      src.write('\n')
      src.write('#include <string.h> /* strlen */\n')
      src.write('#include <stdlib.h> /* malloc/free */\n')
      src.write('\n')

      v = []
      for i in range(0,256):
        try:
          v.append(ord(bytes([i]).decode(e)[0]))
        except:
          v.append(0xffff)
          pass

      src.write('static const uint16_t %s_utf8[256] =\n'%(name))
      src.write('{\n')
      for i in range(0,256,16):
        src.write('  %s,\n'%(', '.join([ '0x%04x'%(i) for i in v[i:i+16]])))
      src.write('};\n')

      src.write('\n')
      src.write('int tutf8e_string_encode_%s(char *output, size_t olen, const char *input)\n'%(name))
      src.write('{\n')
      src.write('  size_t len = strlen(input) + 1;\n')
      src.write('  return tutf8e_buffer_encode(%s_utf8, input, len, output, olen);\n'%(name))
      src.write('}\n')

      src.write('\n')
      src.write('int tutf8e_buffer_encode_%s(char *output, size_t olen, const char *input, size_t ilen)\n'%(name))
      src.write('{\n')
      src.write('  return tutf8e_buffer_encode(%s_utf8, input, ilen, output, olen);\n'%(name))
      src.write('}\n')

      src.write('\n')
      src.write('char * tutf8e_string_encode_%s_realloc(char *input)\n'%(name))
      src.write('{\n')
      src.write('  size_t ilen = 0;\n')
      src.write('  size_t olen = 0;\n')
      src.write('  if (input && !tutf8e_string_length(%s_utf8, input, &ilen, &olen) && ilen && olen && ilen!=olen) {\n'%(name))
      src.write('    char * output = malloc(olen + 1);\n')
      src.write('    if (output && !tutf8e_buffer_encode(%s_utf8, input, ilen, output, olen)) {\n'%(name))
      src.write('      free(input);\n')
      src.write('      output[olen] = 0;\n')
      src.write('      return output;\n')
      src.write('    }\n')
      src.write('    free(output);\n')
      src.write('  }\n')
      src.write('  return input;\n')
      src.write('}\n')

  include.write('\n')
  include.write('#endif\n')

# TESTS

# List of pangrams
# http://clagnut.com/blog/2380/

tests = [
  ('english',  'iso-8859-1',  'A quick brown fox jumps over the lazy dog'),
  ('czech',    'iso-8859-2',  'Nechť již hříšné saxofony ďáblů rozezvučí síň úděsnými tóny waltzu, tanga a quickstepu.'),
  ('turkish',  'iso-8859-3',  'Pijamalı hasta yağız şoföre çabucak güvendi.'),
  ('estonian', 'iso-8859-4',  'Põdur Zagrebi tšellomängija-följetonist Ciqo külmetas kehvas garaažis'),
  ('russian',  'iso-8859-5',  'В чащах юга жил бы цитрус? Да, но фальшивый экземпляр!'),
  ('greek',    'iso-8859-7',  'διαφυλάξτε γενικά τη ζωή σας από βαθειά ψυχικά τραύματα'),
  ('hebrew',   'iso-8859-8',  'עטלף אבק נס דרך מזגן שהתפוצץ כי חם'),
  ('turkish2', 'iso-8859-9',  'Pijamalı hasta yağız şoföre çabucak güvendi.'),
  ('swedish',  'iso-8859-10', 'Flygande bäckasiner söka hwila på mjuka tuvor.'),
  ('thai',     'iso-8859-11', 'เป็นมนุษย์สุดประเสริฐเลิศคุณค่า กว่าบรรดาฝูงสัตว์เดรัจฉาน จงฝ่าฟันพัฒนาวิชาการ อย่าล้างผลาญฤๅเข่นฆ่าบีฑาใคร ไม่ถือโทษโกรธแช่งซัดฮึดฮัดด่า หัดอภัยเหมือนกีฬาอัชฌาสัย ปฏิบัติประพฤติกฎกำหนดใจ พูดจาให้จ๊ะๆ จ๋าๆ น่าฟังเอยฯ'),
  ('polish',   'iso-8859-13', 'Jeżu klątw, spłódź Finom część gry hańb!')
]

with open('test/test.c', 'w') as test:

  test.write('#include <tutf8e.h>\n')
  test.write('\n')
  test.write('#include <stdio.h>\n')
  test.write('#include <string.h>\n')
  test.write('#include <stdlib.h>\n')
  test.write('\n')
  test.write('int main(int argc, char *argv[])\n')
  test.write('{\n')
  test.write('  int pass = 0;\n')
  test.write('  int fail = 0;\n')
  test.write('  int ret;\n')
  test.write('  size_t len;\n')
  test.write('  char buffer[1024];\n')
  test.write('  char *encoded;\n')
  test.write('\n')

  for i in tests:
    if i[1] in encodings:
      test.write('  static const char %s[] = {\n'%(i[0]))
      data = [i for i in i[2].encode(i[1])] + [ 0 ]
      for i in range(0, len(data), 24):
        test.write('    %s,\n'%(', '.join([ '0x%02x'%(j) for j in data[i:i+24]])))
      test.write('  };\n')

  test.write('\n')
  for i in tests:
    if i[1] in encodings:
      test.write('  static const char %sUTF8[] = {\n'%(i[0]))
      data = [i for i in i[2].encode('utf-8')] + [ 0 ]
      for i in range(0, len(data), 24):
        test.write('    %s,\n'%(', '.join([ '0x%02x'%(j) for j in data[i:i+24]])))
      test.write('  };\n')

  test.write('\n  /* string encode to UTF8 */\n')
  for i in tests:
    if i[1] in encodings:
      name = i[1].replace('-', '_').lower()
      test.write('  ret = tutf8e_string_encode_%s(buffer, sizeof(buffer), %s);\n'%(name, i[0]))
      test.write('  if (!ret && !strcmp(buffer, %sUTF8)) {\n'%(i[0]))
      test.write('    printf("%s\\n", buffer);\n')
      test.write('    pass++;\n')
      test.write('  } else {\n')
      test.write('    printf("Failed to encode %s test\\n");\n'%(i[0]))
      test.write('    fail++;\n')
      test.write('  }\n')
      test.write('\n')

  test.write('\n  /* buffer encode to UTF8 */\n')
  for i in tests:
    if i[1] in encodings:
      name = i[1].replace('-', '_').lower()
      test.write('  len = strlen(%s);\n'%(i[0]))
      test.write('  ret = tutf8e_buffer_encode_%s(buffer, sizeof(buffer), %s, len);\n'%(name, i[0]))
      test.write('  if (!ret && !strncmp(buffer, %sUTF8, len)) {\n'%(i[0]))
      test.write('    pass++;\n')
      test.write('  } else {\n')
      test.write('    printf("Failed to encode %s test\\n");\n'%(i[0]))
      test.write('    fail++;\n')
      test.write('  }\n')
      test.write('\n')

  test.write('\n  /* string encode with possible re-allocation to UTF8 */\n')
  for i in tests:
    if i[1] in encodings:
      name = i[1].replace('-', '_').lower()
      test.write('  encoded = tutf8e_string_encode_%s_realloc(strdup(%s));\n'%(name, i[0]))
      test.write('  if (encoded && !strcmp(encoded, %sUTF8)) {\n'%(i[0]))
      test.write('    printf("%s\\n", encoded);\n')
      test.write('    pass++;\n')
      test.write('  } else {\n')
      test.write('    printf("Failed to encode %s test\\n");\n'%(i[0]))
      test.write('    fail++;\n')
      test.write('  }\n')
      test.write('\n')

  test.write('  printf("%d passed, %d failed tests\\n", pass, fail);\n')

  test.write('}\n')

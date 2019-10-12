#!/usr/bin/env python3

encodings = [
  'windows-1250', 'windows-1251', 'windows-1252', 'windows-1253', 'windows-1254',
  'windows-1255',  'windows-1256', 'windows-1257', 'windows-1258',
  'iso-8859-1', 'iso-8859-2', 'iso-8859-3', 'iso-8859-4', 'iso-8859-5', 'iso-8859-6', 'iso-8859-7', 'iso-8859-8', 'iso-8859-9', 'iso-8859-10',
  'iso-8859-11', 'iso-8859-13', 'iso-8859-14', 'iso-8859-15', 'iso-8859-16'
  ]

with open('include/tutf8e.h', 'w') as include:

  include.write('#ifndef TUTF8E_H\n')
  include.write('#define TUTF8E_H\n')
  include.write('\n')
  include.write('#include <stddef.h>  /* size_t */\n')
  include.write('#include <stdint.h>  /* uint16_t */\n')
  include.write('\n')

  for e in sorted(encodings):

    mapping  = {}
    domain   = []

    name = e.replace('-', '_').lower()

    print('Encoding: %s'%(e))

    include.write('extern int encode_%s_utf8(char *dest, size_t size, const char *src);\n'%(name))

    with open('src/%s.c'%(name), 'w') as src:

      # Emit code

      src.write('#include <stddef.h>  /* size_t */\n')
      src.write('#include <stdint.h>  /* uint16_t */\n')
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
      src.write('int encode_%s_utf8(char *dest, size_t size, const char *src)\n'%(name))
      src.write('{\n')

      src.write('  unsigned char *o = (unsigned char *) dest;\n')
      src.write('  for (const unsigned char *i = (unsigned char *) src; *i; ++i) {\n')
      src.write('    uint16_t c = %s_utf8[*i];\n'%(name))
      src.write('    if (c<0x80) {\n')
      src.write('      if (size<1) return -2;\n')
      src.write('      *o++ = c;\n')
      src.write('      size--;\n')
      src.write('      continue;\n')
      src.write('    }\n')
      src.write('    if (c<0x800) {\n')
      src.write('      if (size<2) return -2;\n')
      src.write('      *o++ = 0xc0 | (c>>6);\n')
      src.write('      *o++ = 0x80 | (c&0x3f);\n')
      src.write('      size -= 2;\n')
      src.write('      continue;\n')
      src.write('    }\n')
      src.write('    if (c<0xffff) {\n')
      src.write('      if (size<3) return -2;\n')
      src.write('      *o++ = 0xe0 | (c>>12);\n')
      src.write('      *o++ = 0x80 | ((c>>6)&0x3f);\n')
      src.write('      *o++ = 0x80 | (c&0x3f);\n')
      src.write('      size -= 3;\n')
      src.write('      continue;\n')
      src.write('    }\n')
      src.write('    return -1;\n')
      src.write('  }\n')
      src.write('  if (size<1) return -2;\n')
      src.write('  *o++ = 0;\n')
      src.write('  return 0;\n')
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
  test.write('  char buffer[1024];\n')
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

  test.write('\n')
  for i in tests:
    if i[1] in encodings:
      test.write('  ret = encode_%s_utf8(buffer, sizeof(buffer), %s);\n'%(i[1].replace('-', '_').lower(), i[0]))
      test.write('  if (!ret && !strcmp(buffer, %sUTF8)) { \n'%(i[0]))
      test.write('    printf("%s\\n", buffer);\n')
      test.write('    pass++;\n')
      test.write('  } else {\n')
      test.write('    printf("Failed to decode %s test\\n");\n'%(i[0]))
      test.write('    fail++;\n')
      test.write('  }\n')
      test.write('\n')

  test.write('  printf("%d passed, %d failed tests\\n", pass, fail);\n')

  test.write('}\n')

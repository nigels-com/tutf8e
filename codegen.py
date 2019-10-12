#!/usr/bin/env python3

encodings = [ 
  'windows-1251', 'windows-1252', 'windows-1253', 'windows-1254', 'windows-1255',  'windows-1256', 'windows-1257', 'windows-1258',
  'iso-8859-1', 'iso-8859-2', 'iso-8859-3', 'iso-8859-4', 'iso-8859-5', 'iso-8859-6', 'iso-8859-7', 'iso-8859-8', 'iso-8859-9', 'iso-8859-10',
  'iso-8859-11', 'iso-8859-13', 'iso-8859-14', 'iso-8859-15', 'iso-8859-16'
  ]

for e in encodings:

  mapping  = {}
  domain   = []

  name = e.replace('-', '_').lower()

  print('Encoding: %s'%(e))

  for i in range(0,256):
    try:
      v = ord(bytes([i]).decode(e)[0])
      mapping[i] = v
      domain.append(i)
    except:
      pass

  #print(mapping)
  #print(domain)

  # Segment the domain into contiguous ranges of same UTF-8 length

  segments = []
  s = []
  for i in domain:
    if not len(s):
      s.append(i)
    else:
      j = s[-1]
      if mapping[j]+1==mapping[i] and (i<128 and j<128 or i>128 and j>128):
        s.append(i)
      else:
        segments.append(s)
        s = []
  if len(s):
    segments.append(s)

  #print(segments)

  # Simplify segments

  segments = [ [i[0], i[-1]] for i in segments ]

  print(segments)


  with open('src/%s.c'%(name), 'w') as f:

    # Emit code

    f.write('#include <stddef.h>  /* size_t */\n')
    f.write('#include <stdint.h>  /* uint16_t */\n')
    f.write('\n')
    f.write('int encode_%s_utf8(char *dest, size_t size, const char *src)\n'%(name))
    f.write('{\n')

    f.write('  unsigned char *o = (unsigned char *) dest;\n')
    f.write('  unsigned char *end = dest + size;\n')
    f.write('  for (const unsigned char *i = (unsigned char *) src; *i; ++i) {\n')

    if len(segments):
        for i in segments:
            if i[0]>0:
              f.write('    if (*i<%d) return -1;\n'%(i[0]))
            if i[1]==255:
              f.write('    /* if (*i<=255) */ {\n')
            else:
              if i[0]==i[1]:
                f.write('    if (*i==%d) {\n'%(i[1]))
              else:
                f.write('    if (*i<=%d) {\n'%(i[1]))
            v = mapping[i[0]]
            if v<0x80:
              f.write('      if (end-o < 1) return -2;\n')
              if v==0:
                if i[0]==0:
                  f.write('      *o++ = *i;\n')
                else:
                  f.write('      *o++ = *i - %d;\n'%(i[0]))
              else:
                f.write('      *o++ = 0x%04x + *i - %d;\n'%(mapping[i[0]], i[0]))
            elif v<0x800:
                f.write('      if (end-o < 2) return -2;\n')
                if i[0]==i[1]:
                    f.write('      *o++ = 0xc0 | (0x%04x>>6);\n'%(mapping[i[0]]))
                    f.write('      *o++ = 0x80 | (0x%04x&0x3f);\n'%(mapping[i[0]]))
                else:
                    if i[0]==v:
                      f.write('      *o++ = 0xc0 | (*i>>6);\n')
                      f.write('      *o++ = 0x80 | (*i&0x3f);\n')
                    else:
                      f.write('      uint16_t v = 0x%04x + *i - %du;\n'%(mapping[i[0]], i[0]))
                      f.write('      *o++ = 0xc0 | (v>>6);\n')
                      f.write('      *o++ = 0x80 | (v&0x3f);\n')
            elif v<0x10000:
                f.write('      if (end-o < 3) return -2;\n')
                if i[0]==i[1]:
                    f.write('      *o++ = 0xe0 | (0x%04x>>12);\n'%(mapping[i[0]]))
                    f.write('      *o++ = 0x80 | ((0x%04x>>6)&0x3f);\n'%(mapping[i[0]]))
                    f.write('      *o++ = 0x80 | (0x%04x&0x3f);\n'%(mapping[i[0]]))
                else:
                    if i[0]==v:
                      f.write('      *o++ = 0xe0 | (*i>>12);\n')
                      f.write('      *o++ = 0x80 | ((*i>>6)&0x3f);\n')
                      f.write('      *o++ = 0x80 | (*i&0x3f);\n')
                    else:
                      f.write('      uint16_t v = 0x%04x + *i - %du;\n'%(mapping[i[0]], i[0]))
                      f.write('      *o++ = 0xe0 | (v>>12);\n')
                      f.write('      *o++ = 0x80 | ((v>>6)&0x3f);\n')
                      f.write('      *o++ = 0x80 | (v&0x3f);\n')
            f.write('      continue;\n')
            f.write('    }\n')
        f.write('    return -1;\n')
    f.write('  }\n')
    f.write('  return 0;\n')
    f.write('}\n')

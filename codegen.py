#

# for i in range(0,256): print('%x -> %s'%(i, ' '.join(map(str, bytes([i]).decode('CP1252').encode('utf-8')))))
# ord(bytes([127]).decode('Windows-1252')[0])



encoding = 'Windows-1252'
#encoding = 'windows-1252'
#encoding = 'iso-8859-1'
#encoding = 'iso-8859-15'
mapping  = {}
domain   = []

print('Encoding: %s'%(encoding))

for i in range(0,256):
  try:
    v = ord(bytes([i]).decode(encoding)[0])
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

print('  unsigned char *o = output;')
print('  unsigned char *end = output + size;')
print('  for (const unsigned char *i = input; *i; ++i) {')
#print('    const char c = *i;')
# Emit code
if len(segments):
    for i in segments:
        if i[0]>0:
          print('    if (*i<%d) goto undef;'%(i[0]))
        if i[1]==255:
          print('    /* if (*i<=255) */ {')
        else:
          if i[0]==i[1]:
            print('    if (*i==%d) {'%(i[1]))
          else:
            print('    if (*i<=%d) {'%(i[1]))
        v = mapping[i[0]]
        if v<0x80:
          print('      if (end-o < 1) goto bufferTooSmall;')
          if v==0:
            if i[0]==0:
              print('      *o++ = *i;')
            else:
              print('      *o++ = *i - %d;'%(i[0]))
          else:
            print('      *o++ = 0x%04x + *i - %d;'%(mapping[i[0]], i[0]))
        elif v<0x800:
            print('      if (end-o < 2) goto bufferTooSmall;')
            if i[0]==i[1]:
                print('      *o++ = 0xc0 | (0x%04x>>6);'%(mapping[i[0]]))
                print('      *o++ = 0x80 | (0x%04x&0x3f);'%(mapping[i[0]]))
            else:
                if i[0]==v:
                  print('      *o++ = 0xc0 | (*i>>6);')
                  print('      *o++ = 0x80 | (*i&0x3f);')
                else:
                  print('      uint16_t v = 0x%04x + *i - %du;'%(mapping[i[0]], i[0]))
                  print('      *o++ = 0xc0 | (v>>6);')
                  print('      *o++ = 0x80 | (v&0x3f);')
        elif v<0x10000:
            print('      if (end-o < 3) goto bufferTooSmall;')
            if i[0]==i[1]:
                print('      *o++ = 0xe0 | (0x%04x>>12);'%(mapping[i[0]]))
                print('      *o++ = 0x80 | ((0x%04x>>6)&0x3f);'%(mapping[i[0]]))
                print('      *o++ = 0x80 | (0x%04x&0x3f);'%(mapping[i[0]]))
            else:
                if i[0]==v:
                  print('      *o++ = 0xe0 | (*i>>12);')
                  print('      *o++ = 0x80 | ((*i>>6)&0x3f);')
                  print('      *o++ = 0x80 | (*i&0x3f);')
                else:
                  print('      uint16_t v = 0x%4x + *i - %du;'%(mapping[i[0]], i[0]))
                  print('      *o++ = 0xe0 | (v>>12);')
                  print('      *o++ = 0x80 | ((v>>6)&0x3f);')
                  print('      *o++ = 0x80 | (v&0x3f);')
        print('      continue;')
        print('    }')
    print('    goto undef;')
print('  }')

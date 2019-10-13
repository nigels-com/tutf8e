#include <tutf8e.h>

int encode_utf8(const uint16_t *table, const char **ibuf, size_t *ileft, char **obuf, size_t *oleft)
{
  const unsigned char **i = (const unsigned char **) ibuf;
  unsigned char **o = (unsigned char **) obuf;
  for (; *ileft; *i += 1, *ileft -= 1) {
    uint16_t c = table[**i];
    if (c<0x80) {
      if (*oleft<1) return -2;
      (*o)[0] = c;
      *o += 1;
      *oleft -= 1;
      continue;
    }
    if (c<0x800) {
      if (*oleft<2) return -2;
      (*o)[0] = 0xc0 | (c>>6);
      (*o)[1] = 0x80 | (c&0x3f);
      *o += 2;
      *oleft -= 2;
      continue;
    }
    if (c<0xffff) {
      if (*oleft<3) return -2;
      (*o)[0] = 0xe0 | (c>>12);
      (*o)[1] = 0x80 | ((c>>6)&0x3f);
      (*o)[2] = 0x80 | (c&0x3f);
      *o += 3;
      *oleft -= 3;
      continue;
    }
    return -1;
  }
  return 0;
}

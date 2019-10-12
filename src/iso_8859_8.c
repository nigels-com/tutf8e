#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_8_utf8(char *dest, size_t size, const char *src)
{
  unsigned char *o = (unsigned char *) dest;
  unsigned char *end = dest + size;
  for (const unsigned char *i = (unsigned char *) src; *i; ++i) {
    if (*i<=127) {
      if (end-o < 1) return -2;
      *o++ = *i;
      continue;
    }
    if (*i<129) return -1;
    if (*i<=160) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<163) return -1;
    if (*i<=169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i<=185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i<=190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<224) return -1;
    if (*i<=250) {
      if (end-o < 2) return -2;
      uint16_t v = 0x05d0 + *i - 224u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x200f>>12);
      *o++ = 0x80 | ((0x200f>>6)&0x3f);
      *o++ = 0x80 | (0x200f&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_5_utf8(char *dest, size_t size, const char *src)
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
    if (*i<162) return -1;
    if (*i<=172) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0402 + *i - 162u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<174) return -1;
    if (*i<=239) {
      if (end-o < 2) return -2;
      uint16_t v = 0x040e + *i - 174u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i<=252) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0451 + *i - 241u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<254) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      uint16_t v = 0x045e + *i - 254u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

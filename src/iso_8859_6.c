#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_6_utf8(char *dest, size_t size, const char *src)
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
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x060c>>6);
      *o++ = 0x80 | (0x060c&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i==187) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x061b>>6);
      *o++ = 0x80 | (0x061b&0x3f);
      continue;
    }
    if (*i<193) return -1;
    if (*i<=218) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0621 + *i - 193u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<225) return -1;
    if (*i<=242) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0641 + *i - 225u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

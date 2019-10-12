#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_15_utf8(char *dest, size_t size, const char *src)
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
    if (*i<=163) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<165) return -1;
    if (*i==165) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a5>>6);
      *o++ = 0x80 | (0x00a5&0x3f);
      continue;
    }
    if (*i<167) return -1;
    if (*i==167) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a7>>6);
      *o++ = 0x80 | (0x00a7&0x3f);
      continue;
    }
    if (*i<169) return -1;
    if (*i<=179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<181) return -1;
    if (*i<=183) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i<=187) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0153>>6);
      *o++ = 0x80 | (0x0153&0x3f);
      continue;
    }
    if (*i<191) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

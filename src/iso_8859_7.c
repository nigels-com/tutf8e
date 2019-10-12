#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_7_utf8(char *dest, size_t size, const char *src)
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
    if (*i==162) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2019>>12);
      *o++ = 0x80 | ((0x2019>>6)&0x3f);
      *o++ = 0x80 | (0x2019&0x3f);
      continue;
    }
    if (*i<164) return -1;
    if (*i==164) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x20ac>>12);
      *o++ = 0x80 | ((0x20ac>>6)&0x3f);
      *o++ = 0x80 | (0x20ac&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i<=169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i<=173) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i<=179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<181) return -1;
    if (*i<=182) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0385 + *i - 181u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<184) return -1;
    if (*i<=186) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0388 + *i - 184u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x038c>>6);
      *o++ = 0x80 | (0x038c&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i<=209) {
      if (end-o < 2) return -2;
      uint16_t v = 0x038e + *i - 190u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<212) return -1;
    if (*i<=254) {
      if (end-o < 2) return -2;
      uint16_t v = 0x03a4 + *i - 212u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

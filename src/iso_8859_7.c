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
    if (*i<128) return -1;
    if (*i==128) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0080>>6);
      *o++ = 0x80 | (0x0080&0x3f);
      continue;
    }
    if (*i<129) return -1;
    if (*i<=160) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<161) return -1;
    if (*i<=162) {
      if (end-o < 3) return -2;
      uint16_t v = 0x2018 + *i - 161u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<163) return -1;
    if (*i==163) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a3>>6);
      *o++ = 0x80 | (0x00a3&0x3f);
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
    if (*i<165) return -1;
    if (*i==165) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x20af>>12);
      *o++ = 0x80 | ((0x20af>>6)&0x3f);
      *o++ = 0x80 | (0x20af&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i<=169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x037a>>6);
      *o++ = 0x80 | (0x037a&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i<=173) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<175) return -1;
    if (*i==175) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2015>>12);
      *o++ = 0x80 | ((0x2015>>6)&0x3f);
      *o++ = 0x80 | (0x2015&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i<=179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i<=182) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0384 + *i - 180u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<183) return -1;
    if (*i==183) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b7>>6);
      *o++ = 0x80 | (0x00b7&0x3f);
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
    if (*i<187) return -1;
    if (*i==187) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00bb>>6);
      *o++ = 0x80 | (0x00bb&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x038c>>6);
      *o++ = 0x80 | (0x038c&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00bd>>6);
      *o++ = 0x80 | (0x00bd&0x3f);
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
    if (*i<211) return -1;
    if (*i<=254) {
      if (end-o < 2) return -2;
      uint16_t v = 0x03a3 + *i - 211u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    return -1;
  }
  if (end-o < 1) return -2;
  *o++ = 0;
  return 0;
}

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_windows_1253_utf8(char *dest, size_t size, const char *src)
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
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x20ac>>12);
      *o++ = 0x80 | ((0x20ac>>6)&0x3f);
      *o++ = 0x80 | (0x20ac&0x3f);
      continue;
    }
    if (*i<130) return -1;
    if (*i==130) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x201a>>12);
      *o++ = 0x80 | ((0x201a>>6)&0x3f);
      *o++ = 0x80 | (0x201a&0x3f);
      continue;
    }
    if (*i<131) return -1;
    if (*i==131) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0192>>6);
      *o++ = 0x80 | (0x0192&0x3f);
      continue;
    }
    if (*i<132) return -1;
    if (*i==132) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x201e>>12);
      *o++ = 0x80 | ((0x201e>>6)&0x3f);
      *o++ = 0x80 | (0x201e&0x3f);
      continue;
    }
    if (*i<133) return -1;
    if (*i==133) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2026>>12);
      *o++ = 0x80 | ((0x2026>>6)&0x3f);
      *o++ = 0x80 | (0x2026&0x3f);
      continue;
    }
    if (*i<134) return -1;
    if (*i<=135) {
      if (end-o < 3) return -2;
      uint16_t v = 0x2020 + *i - 134u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<137) return -1;
    if (*i==137) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2030>>12);
      *o++ = 0x80 | ((0x2030>>6)&0x3f);
      *o++ = 0x80 | (0x2030&0x3f);
      continue;
    }
    if (*i<139) return -1;
    if (*i==139) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2039>>12);
      *o++ = 0x80 | ((0x2039>>6)&0x3f);
      *o++ = 0x80 | (0x2039&0x3f);
      continue;
    }
    if (*i<145) return -1;
    if (*i<=146) {
      if (end-o < 3) return -2;
      uint16_t v = 0x2018 + *i - 145u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<147) return -1;
    if (*i<=148) {
      if (end-o < 3) return -2;
      uint16_t v = 0x201c + *i - 147u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<149) return -1;
    if (*i==149) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2022>>12);
      *o++ = 0x80 | ((0x2022>>6)&0x3f);
      *o++ = 0x80 | (0x2022&0x3f);
      continue;
    }
    if (*i<150) return -1;
    if (*i<=151) {
      if (end-o < 3) return -2;
      uint16_t v = 0x2013 + *i - 150u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<153) return -1;
    if (*i==153) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2122>>12);
      *o++ = 0x80 | ((0x2122>>6)&0x3f);
      *o++ = 0x80 | (0x2122&0x3f);
      continue;
    }
    if (*i<155) return -1;
    if (*i==155) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x203a>>12);
      *o++ = 0x80 | ((0x203a>>6)&0x3f);
      *o++ = 0x80 | (0x203a&0x3f);
      continue;
    }
    if (*i<160) return -1;
    if (*i==160) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a0>>6);
      *o++ = 0x80 | (0x00a0&0x3f);
      continue;
    }
    if (*i<161) return -1;
    if (*i<=162) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0385 + *i - 161u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
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
    if (*i<=174) {
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
    if (*i==180) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0384>>6);
      *o++ = 0x80 | (0x0384&0x3f);
      continue;
    }
    if (*i<181) return -1;
    if (*i<=183) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
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

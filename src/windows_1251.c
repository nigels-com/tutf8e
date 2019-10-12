#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_windows_1251_utf8(char *dest, size_t size, const char *src)
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
    if (*i==129) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0403>>6);
      *o++ = 0x80 | (0x0403&0x3f);
      continue;
    }
    if (*i<131) return -1;
    if (*i==131) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0453>>6);
      *o++ = 0x80 | (0x0453&0x3f);
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
    if (*i<135) return -1;
    if (*i==135) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2021>>12);
      *o++ = 0x80 | ((0x2021>>6)&0x3f);
      *o++ = 0x80 | (0x2021&0x3f);
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
    if (*i<141) return -1;
    if (*i==141) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x040c>>6);
      *o++ = 0x80 | (0x040c&0x3f);
      continue;
    }
    if (*i<143) return -1;
    if (*i==143) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x040f>>6);
      *o++ = 0x80 | (0x040f&0x3f);
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
    if (*i<148) return -1;
    if (*i==148) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x201d>>12);
      *o++ = 0x80 | ((0x201d>>6)&0x3f);
      *o++ = 0x80 | (0x201d&0x3f);
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
    if (*i<154) return -1;
    if (*i==154) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0459>>6);
      *o++ = 0x80 | (0x0459&0x3f);
      continue;
    }
    if (*i<156) return -1;
    if (*i==156) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045a>>6);
      *o++ = 0x80 | (0x045a&0x3f);
      continue;
    }
    if (*i<158) return -1;
    if (*i==158) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045b>>6);
      *o++ = 0x80 | (0x045b&0x3f);
      continue;
    }
    if (*i<160) return -1;
    if (*i==160) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a0>>6);
      *o++ = 0x80 | (0x00a0&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i==162) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045e>>6);
      *o++ = 0x80 | (0x045e&0x3f);
      continue;
    }
    if (*i<164) return -1;
    if (*i==164) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a4>>6);
      *o++ = 0x80 | (0x00a4&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i<=167) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<169) return -1;
    if (*i==169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a9>>6);
      *o++ = 0x80 | (0x00a9&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i<=174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i<=177) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<179) return -1;
    if (*i==179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0456>>6);
      *o++ = 0x80 | (0x0456&0x3f);
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
    if (*i==185) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2116>>12);
      *o++ = 0x80 | ((0x2116>>6)&0x3f);
      *o++ = 0x80 | (0x2116&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i==187) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00bb>>6);
      *o++ = 0x80 | (0x00bb&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0405>>6);
      *o++ = 0x80 | (0x0405&0x3f);
      continue;
    }
    if (*i<191) return -1;
    if (*i==191) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0457>>6);
      *o++ = 0x80 | (0x0457&0x3f);
      continue;
    }
    if (*i<193) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      uint16_t v = 0x0411 + *i - 193u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

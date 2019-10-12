#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_windows_1256_utf8(char *dest, size_t size, const char *src)
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
      *o++ = 0xc0 | (0x067e>>6);
      *o++ = 0x80 | (0x067e&0x3f);
      continue;
    }
    if (*i<131) return -1;
    if (*i==131) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0192>>6);
      *o++ = 0x80 | (0x0192&0x3f);
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
      *o++ = 0xc0 | (0x0686>>6);
      *o++ = 0x80 | (0x0686&0x3f);
      continue;
    }
    if (*i<143) return -1;
    if (*i==143) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0688>>6);
      *o++ = 0x80 | (0x0688&0x3f);
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
    if (*i<157) return -1;
    if (*i<=158) {
      if (end-o < 3) return -2;
      uint16_t v = 0x200c + *i - 157u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
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
    if (*i<192) return -1;
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06c1>>6);
      *o++ = 0x80 | (0x06c1&0x3f);
      continue;
    }
    if (*i<194) return -1;
    if (*i<=214) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0622 + *i - 194u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<216) return -1;
    if (*i<=219) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0637 + *i - 216u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<221) return -1;
    if (*i<=223) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0641 + *i - 221u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<225) return -1;
    if (*i==225) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0644>>6);
      *o++ = 0x80 | (0x0644&0x3f);
      continue;
    }
    if (*i<227) return -1;
    if (*i<=230) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0645 + *i - 227u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<232) return -1;
    if (*i<=235) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<237) return -1;
    if (*i==237) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x064a>>6);
      *o++ = 0x80 | (0x064a&0x3f);
      continue;
    }
    if (*i<239) return -1;
    if (*i==239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ef>>6);
      *o++ = 0x80 | (0x00ef&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i<=243) {
      if (end-o < 2) return -2;
      uint16_t v = 0x064c + *i - 241u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<245) return -1;
    if (*i<=246) {
      if (end-o < 2) return -2;
      uint16_t v = 0x064f + *i - 245u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i==248) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0651>>6);
      *o++ = 0x80 | (0x0651&0x3f);
      continue;
    }
    if (*i<250) return -1;
    if (*i==250) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0652>>6);
      *o++ = 0x80 | (0x0652&0x3f);
      continue;
    }
    if (*i<252) return -1;
    if (*i==252) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00fc>>6);
      *o++ = 0x80 | (0x00fc&0x3f);
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

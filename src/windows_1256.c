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
    if (*i<128) return -1;
    if (*i==128) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x20ac>>12);
      *o++ = 0x80 | ((0x20ac>>6)&0x3f);
      *o++ = 0x80 | (0x20ac&0x3f);
      continue;
    }
    if (*i<129) return -1;
    if (*i==129) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x067e>>6);
      *o++ = 0x80 | (0x067e&0x3f);
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
    if (*i<136) return -1;
    if (*i==136) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02c6>>6);
      *o++ = 0x80 | (0x02c6&0x3f);
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
    if (*i<138) return -1;
    if (*i==138) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0679>>6);
      *o++ = 0x80 | (0x0679&0x3f);
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
    if (*i<140) return -1;
    if (*i==140) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0152>>6);
      *o++ = 0x80 | (0x0152&0x3f);
      continue;
    }
    if (*i<141) return -1;
    if (*i==141) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0686>>6);
      *o++ = 0x80 | (0x0686&0x3f);
      continue;
    }
    if (*i<142) return -1;
    if (*i==142) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0698>>6);
      *o++ = 0x80 | (0x0698&0x3f);
      continue;
    }
    if (*i<143) return -1;
    if (*i==143) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0688>>6);
      *o++ = 0x80 | (0x0688&0x3f);
      continue;
    }
    if (*i<144) return -1;
    if (*i==144) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06af>>6);
      *o++ = 0x80 | (0x06af&0x3f);
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
    if (*i<152) return -1;
    if (*i==152) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06a9>>6);
      *o++ = 0x80 | (0x06a9&0x3f);
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
    if (*i<154) return -1;
    if (*i==154) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0691>>6);
      *o++ = 0x80 | (0x0691&0x3f);
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
    if (*i<156) return -1;
    if (*i==156) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0153>>6);
      *o++ = 0x80 | (0x0153&0x3f);
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
    if (*i<159) return -1;
    if (*i==159) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06ba>>6);
      *o++ = 0x80 | (0x06ba&0x3f);
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
    if (*i==161) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x060c>>6);
      *o++ = 0x80 | (0x060c&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i<=169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06be>>6);
      *o++ = 0x80 | (0x06be&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i<=185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x061b>>6);
      *o++ = 0x80 | (0x061b&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i<=190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<191) return -1;
    if (*i==191) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x061f>>6);
      *o++ = 0x80 | (0x061f&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06c1>>6);
      *o++ = 0x80 | (0x06c1&0x3f);
      continue;
    }
    if (*i<193) return -1;
    if (*i<=214) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0621 + *i - 193u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<215) return -1;
    if (*i==215) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d7>>6);
      *o++ = 0x80 | (0x00d7&0x3f);
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
    if (*i<220) return -1;
    if (*i<=223) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0640 + *i - 220u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<224) return -1;
    if (*i==224) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e0>>6);
      *o++ = 0x80 | (0x00e0&0x3f);
      continue;
    }
    if (*i<225) return -1;
    if (*i==225) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0644>>6);
      *o++ = 0x80 | (0x0644&0x3f);
      continue;
    }
    if (*i<226) return -1;
    if (*i==226) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e2>>6);
      *o++ = 0x80 | (0x00e2&0x3f);
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
    if (*i<231) return -1;
    if (*i<=235) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<236) return -1;
    if (*i<=237) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0649 + *i - 236u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<238) return -1;
    if (*i<=239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<240) return -1;
    if (*i<=243) {
      if (end-o < 2) return -2;
      uint16_t v = 0x064b + *i - 240u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<244) return -1;
    if (*i==244) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f4>>6);
      *o++ = 0x80 | (0x00f4&0x3f);
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
    if (*i<247) return -1;
    if (*i==247) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f7>>6);
      *o++ = 0x80 | (0x00f7&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i==248) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0651>>6);
      *o++ = 0x80 | (0x0651&0x3f);
      continue;
    }
    if (*i<249) return -1;
    if (*i==249) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f9>>6);
      *o++ = 0x80 | (0x00f9&0x3f);
      continue;
    }
    if (*i<250) return -1;
    if (*i==250) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0652>>6);
      *o++ = 0x80 | (0x0652&0x3f);
      continue;
    }
    if (*i<251) return -1;
    if (*i<=252) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<253) return -1;
    if (*i<=254) {
      if (end-o < 3) return -2;
      uint16_t v = 0x200e + *i - 253u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<255) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x06d2>>6);
      *o++ = 0x80 | (0x06d2&0x3f);
      continue;
    }
    return -1;
  }
  if (end-o < 1) return -2;
  *o++ = 0;
  return 0;
}

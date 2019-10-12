#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_windows_1258_utf8(char *dest, size_t size, const char *src)
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
      *o++ = 0xc0 | (0x02dc>>6);
      *o++ = 0x80 | (0x02dc&0x3f);
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
    if (*i<156) return -1;
    if (*i==156) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0153>>6);
      *o++ = 0x80 | (0x0153&0x3f);
      continue;
    }
    if (*i<159) return -1;
    if (*i==159) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0178>>6);
      *o++ = 0x80 | (0x0178&0x3f);
      continue;
    }
    if (*i<160) return -1;
    if (*i<=194) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<195) return -1;
    if (*i==195) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0102>>6);
      *o++ = 0x80 | (0x0102&0x3f);
      continue;
    }
    if (*i<196) return -1;
    if (*i<=203) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<204) return -1;
    if (*i==204) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0300>>6);
      *o++ = 0x80 | (0x0300&0x3f);
      continue;
    }
    if (*i<205) return -1;
    if (*i<=207) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<208) return -1;
    if (*i==208) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0110>>6);
      *o++ = 0x80 | (0x0110&0x3f);
      continue;
    }
    if (*i<209) return -1;
    if (*i==209) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d1>>6);
      *o++ = 0x80 | (0x00d1&0x3f);
      continue;
    }
    if (*i<210) return -1;
    if (*i==210) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0309>>6);
      *o++ = 0x80 | (0x0309&0x3f);
      continue;
    }
    if (*i<211) return -1;
    if (*i<=212) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<213) return -1;
    if (*i==213) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x01a0>>6);
      *o++ = 0x80 | (0x01a0&0x3f);
      continue;
    }
    if (*i<214) return -1;
    if (*i<=220) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<221) return -1;
    if (*i==221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x01af>>6);
      *o++ = 0x80 | (0x01af&0x3f);
      continue;
    }
    if (*i<222) return -1;
    if (*i==222) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0303>>6);
      *o++ = 0x80 | (0x0303&0x3f);
      continue;
    }
    if (*i<223) return -1;
    if (*i<=226) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<227) return -1;
    if (*i==227) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0103>>6);
      *o++ = 0x80 | (0x0103&0x3f);
      continue;
    }
    if (*i<228) return -1;
    if (*i<=235) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<236) return -1;
    if (*i==236) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0301>>6);
      *o++ = 0x80 | (0x0301&0x3f);
      continue;
    }
    if (*i<237) return -1;
    if (*i<=239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<240) return -1;
    if (*i==240) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0111>>6);
      *o++ = 0x80 | (0x0111&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i==241) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f1>>6);
      *o++ = 0x80 | (0x00f1&0x3f);
      continue;
    }
    if (*i<242) return -1;
    if (*i==242) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0323>>6);
      *o++ = 0x80 | (0x0323&0x3f);
      continue;
    }
    if (*i<243) return -1;
    if (*i<=244) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<245) return -1;
    if (*i==245) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x01a1>>6);
      *o++ = 0x80 | (0x01a1&0x3f);
      continue;
    }
    if (*i<246) return -1;
    if (*i<=252) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<253) return -1;
    if (*i==253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x01b0>>6);
      *o++ = 0x80 | (0x01b0&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x20ab>>12);
      *o++ = 0x80 | ((0x20ab>>6)&0x3f);
      *o++ = 0x80 | (0x20ab&0x3f);
      continue;
    }
    if (*i<255) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ff>>6);
      *o++ = 0x80 | (0x00ff&0x3f);
      continue;
    }
    return -1;
  }
  if (end-o < 1) return -2;
  *o++ = 0;
  return 0;
}

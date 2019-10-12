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
    if (*i<128) return -1;
    if (*i==128) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0402>>6);
      *o++ = 0x80 | (0x0402&0x3f);
      continue;
    }
    if (*i<129) return -1;
    if (*i==129) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0403>>6);
      *o++ = 0x80 | (0x0403&0x3f);
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
      *o++ = 0xc0 | (0x0453>>6);
      *o++ = 0x80 | (0x0453&0x3f);
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
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x20ac>>12);
      *o++ = 0x80 | ((0x20ac>>6)&0x3f);
      *o++ = 0x80 | (0x20ac&0x3f);
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
      *o++ = 0xc0 | (0x0409>>6);
      *o++ = 0x80 | (0x0409&0x3f);
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
      *o++ = 0xc0 | (0x040a>>6);
      *o++ = 0x80 | (0x040a&0x3f);
      continue;
    }
    if (*i<141) return -1;
    if (*i==141) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x040c>>6);
      *o++ = 0x80 | (0x040c&0x3f);
      continue;
    }
    if (*i<142) return -1;
    if (*i==142) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x040b>>6);
      *o++ = 0x80 | (0x040b&0x3f);
      continue;
    }
    if (*i<143) return -1;
    if (*i==143) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x040f>>6);
      *o++ = 0x80 | (0x040f&0x3f);
      continue;
    }
    if (*i<144) return -1;
    if (*i==144) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0452>>6);
      *o++ = 0x80 | (0x0452&0x3f);
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
    if (*i<154) return -1;
    if (*i==154) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0459>>6);
      *o++ = 0x80 | (0x0459&0x3f);
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
      *o++ = 0xc0 | (0x045a>>6);
      *o++ = 0x80 | (0x045a&0x3f);
      continue;
    }
    if (*i<157) return -1;
    if (*i==157) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045c>>6);
      *o++ = 0x80 | (0x045c&0x3f);
      continue;
    }
    if (*i<158) return -1;
    if (*i==158) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045b>>6);
      *o++ = 0x80 | (0x045b&0x3f);
      continue;
    }
    if (*i<159) return -1;
    if (*i==159) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045f>>6);
      *o++ = 0x80 | (0x045f&0x3f);
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
      *o++ = 0xc0 | (0x040e>>6);
      *o++ = 0x80 | (0x040e&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i==162) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x045e>>6);
      *o++ = 0x80 | (0x045e&0x3f);
      continue;
    }
    if (*i<163) return -1;
    if (*i==163) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0408>>6);
      *o++ = 0x80 | (0x0408&0x3f);
      continue;
    }
    if (*i<164) return -1;
    if (*i==164) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a4>>6);
      *o++ = 0x80 | (0x00a4&0x3f);
      continue;
    }
    if (*i<165) return -1;
    if (*i==165) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0490>>6);
      *o++ = 0x80 | (0x0490&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i<=167) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<168) return -1;
    if (*i==168) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0401>>6);
      *o++ = 0x80 | (0x0401&0x3f);
      continue;
    }
    if (*i<169) return -1;
    if (*i==169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a9>>6);
      *o++ = 0x80 | (0x00a9&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0404>>6);
      *o++ = 0x80 | (0x0404&0x3f);
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
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0407>>6);
      *o++ = 0x80 | (0x0407&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i<=177) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<178) return -1;
    if (*i==178) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0406>>6);
      *o++ = 0x80 | (0x0406&0x3f);
      continue;
    }
    if (*i<179) return -1;
    if (*i==179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0456>>6);
      *o++ = 0x80 | (0x0456&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i==180) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0491>>6);
      *o++ = 0x80 | (0x0491&0x3f);
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
    if (*i==184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0451>>6);
      *o++ = 0x80 | (0x0451&0x3f);
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
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0454>>6);
      *o++ = 0x80 | (0x0454&0x3f);
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
      *o++ = 0xc0 | (0x0458>>6);
      *o++ = 0x80 | (0x0458&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0405>>6);
      *o++ = 0x80 | (0x0405&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i==190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0455>>6);
      *o++ = 0x80 | (0x0455&0x3f);
      continue;
    }
    if (*i<191) return -1;
    if (*i==191) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0457>>6);
      *o++ = 0x80 | (0x0457&0x3f);
      continue;
    }
    if (*i<192) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      uint16_t v = 0x0410 + *i - 192u;
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

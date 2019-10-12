#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_14_utf8(char *dest, size_t size, const char *src)
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
      uint16_t v = 0x1e02 + *i - 161u;
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
    if (*i<=165) {
      if (end-o < 2) return -2;
      uint16_t v = 0x010a + *i - 164u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i==166) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e0a>>12);
      *o++ = 0x80 | ((0x1e0a>>6)&0x3f);
      *o++ = 0x80 | (0x1e0a&0x3f);
      continue;
    }
    if (*i<167) return -1;
    if (*i==167) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a7>>6);
      *o++ = 0x80 | (0x00a7&0x3f);
      continue;
    }
    if (*i<168) return -1;
    if (*i==168) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e80>>12);
      *o++ = 0x80 | ((0x1e80>>6)&0x3f);
      *o++ = 0x80 | (0x1e80&0x3f);
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
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e82>>12);
      *o++ = 0x80 | ((0x1e82>>6)&0x3f);
      *o++ = 0x80 | (0x1e82&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i==171) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e0b>>12);
      *o++ = 0x80 | ((0x1e0b>>6)&0x3f);
      *o++ = 0x80 | (0x1e0b&0x3f);
      continue;
    }
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1ef2>>12);
      *o++ = 0x80 | ((0x1ef2>>6)&0x3f);
      *o++ = 0x80 | (0x1ef2&0x3f);
      continue;
    }
    if (*i<173) return -1;
    if (*i<=174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<175) return -1;
    if (*i==175) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0178>>6);
      *o++ = 0x80 | (0x0178&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i<=177) {
      if (end-o < 3) return -2;
      uint16_t v = 0x1e1e + *i - 176u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<178) return -1;
    if (*i<=179) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0120 + *i - 178u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i<=181) {
      if (end-o < 3) return -2;
      uint16_t v = 0x1e40 + *i - 180u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i==182) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b6>>6);
      *o++ = 0x80 | (0x00b6&0x3f);
      continue;
    }
    if (*i<183) return -1;
    if (*i==183) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e56>>12);
      *o++ = 0x80 | ((0x1e56>>6)&0x3f);
      *o++ = 0x80 | (0x1e56&0x3f);
      continue;
    }
    if (*i<184) return -1;
    if (*i==184) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e81>>12);
      *o++ = 0x80 | ((0x1e81>>6)&0x3f);
      *o++ = 0x80 | (0x1e81&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i==185) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e57>>12);
      *o++ = 0x80 | ((0x1e57>>6)&0x3f);
      *o++ = 0x80 | (0x1e57&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e83>>12);
      *o++ = 0x80 | ((0x1e83>>6)&0x3f);
      *o++ = 0x80 | (0x1e83&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i==187) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e60>>12);
      *o++ = 0x80 | ((0x1e60>>6)&0x3f);
      *o++ = 0x80 | (0x1e60&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1ef3>>12);
      *o++ = 0x80 | ((0x1ef3>>6)&0x3f);
      *o++ = 0x80 | (0x1ef3&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i<=190) {
      if (end-o < 3) return -2;
      uint16_t v = 0x1e84 + *i - 189u;
      *o++ = 0xe0 | (v>>12);
      *o++ = 0x80 | ((v>>6)&0x3f);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<191) return -1;
    if (*i==191) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e61>>12);
      *o++ = 0x80 | ((0x1e61>>6)&0x3f);
      *o++ = 0x80 | (0x1e61&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i<=207) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<208) return -1;
    if (*i==208) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0174>>6);
      *o++ = 0x80 | (0x0174&0x3f);
      continue;
    }
    if (*i<209) return -1;
    if (*i<=214) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<215) return -1;
    if (*i==215) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e6a>>12);
      *o++ = 0x80 | ((0x1e6a>>6)&0x3f);
      *o++ = 0x80 | (0x1e6a&0x3f);
      continue;
    }
    if (*i<216) return -1;
    if (*i<=221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<222) return -1;
    if (*i==222) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0176>>6);
      *o++ = 0x80 | (0x0176&0x3f);
      continue;
    }
    if (*i<223) return -1;
    if (*i<=239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<240) return -1;
    if (*i==240) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0175>>6);
      *o++ = 0x80 | (0x0175&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i<=246) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<247) return -1;
    if (*i==247) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x1e6b>>12);
      *o++ = 0x80 | ((0x1e6b>>6)&0x3f);
      *o++ = 0x80 | (0x1e6b&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i<=253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0177>>6);
      *o++ = 0x80 | (0x0177&0x3f);
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

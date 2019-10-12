#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_3_utf8(char *dest, size_t size, const char *src)
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
    if (*i==161) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0126>>6);
      *o++ = 0x80 | (0x0126&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i==162) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02d8>>6);
      *o++ = 0x80 | (0x02d8&0x3f);
      continue;
    }
    if (*i<163) return -1;
    if (*i<=164) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i==166) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0124>>6);
      *o++ = 0x80 | (0x0124&0x3f);
      continue;
    }
    if (*i<167) return -1;
    if (*i<=168) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<169) return -1;
    if (*i==169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0130>>6);
      *o++ = 0x80 | (0x0130&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015e>>6);
      *o++ = 0x80 | (0x015e&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i==171) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011e>>6);
      *o++ = 0x80 | (0x011e&0x3f);
      continue;
    }
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0134>>6);
      *o++ = 0x80 | (0x0134&0x3f);
      continue;
    }
    if (*i<173) return -1;
    if (*i==173) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ad>>6);
      *o++ = 0x80 | (0x00ad&0x3f);
      continue;
    }
    if (*i<175) return -1;
    if (*i==175) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017b>>6);
      *o++ = 0x80 | (0x017b&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i==176) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b0>>6);
      *o++ = 0x80 | (0x00b0&0x3f);
      continue;
    }
    if (*i<177) return -1;
    if (*i==177) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0127>>6);
      *o++ = 0x80 | (0x0127&0x3f);
      continue;
    }
    if (*i<178) return -1;
    if (*i<=181) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i==182) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0125>>6);
      *o++ = 0x80 | (0x0125&0x3f);
      continue;
    }
    if (*i<183) return -1;
    if (*i<=184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i==185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0131>>6);
      *o++ = 0x80 | (0x0131&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015f>>6);
      *o++ = 0x80 | (0x015f&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i==187) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011f>>6);
      *o++ = 0x80 | (0x011f&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0135>>6);
      *o++ = 0x80 | (0x0135&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00bd>>6);
      *o++ = 0x80 | (0x00bd&0x3f);
      continue;
    }
    if (*i<191) return -1;
    if (*i==191) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017c>>6);
      *o++ = 0x80 | (0x017c&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i<=194) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<196) return -1;
    if (*i==196) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00c4>>6);
      *o++ = 0x80 | (0x00c4&0x3f);
      continue;
    }
    if (*i<197) return -1;
    if (*i==197) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010a>>6);
      *o++ = 0x80 | (0x010a&0x3f);
      continue;
    }
    if (*i<198) return -1;
    if (*i==198) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0108>>6);
      *o++ = 0x80 | (0x0108&0x3f);
      continue;
    }
    if (*i<199) return -1;
    if (*i<=207) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<209) return -1;
    if (*i<=212) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<213) return -1;
    if (*i==213) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0120>>6);
      *o++ = 0x80 | (0x0120&0x3f);
      continue;
    }
    if (*i<214) return -1;
    if (*i<=215) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<216) return -1;
    if (*i==216) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011c>>6);
      *o++ = 0x80 | (0x011c&0x3f);
      continue;
    }
    if (*i<217) return -1;
    if (*i<=220) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<221) return -1;
    if (*i==221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016c>>6);
      *o++ = 0x80 | (0x016c&0x3f);
      continue;
    }
    if (*i<222) return -1;
    if (*i==222) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015c>>6);
      *o++ = 0x80 | (0x015c&0x3f);
      continue;
    }
    if (*i<223) return -1;
    if (*i<=226) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<228) return -1;
    if (*i==228) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e4>>6);
      *o++ = 0x80 | (0x00e4&0x3f);
      continue;
    }
    if (*i<229) return -1;
    if (*i==229) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010b>>6);
      *o++ = 0x80 | (0x010b&0x3f);
      continue;
    }
    if (*i<230) return -1;
    if (*i==230) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0109>>6);
      *o++ = 0x80 | (0x0109&0x3f);
      continue;
    }
    if (*i<231) return -1;
    if (*i<=239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i<=244) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<245) return -1;
    if (*i==245) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0121>>6);
      *o++ = 0x80 | (0x0121&0x3f);
      continue;
    }
    if (*i<246) return -1;
    if (*i<=247) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i==248) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011d>>6);
      *o++ = 0x80 | (0x011d&0x3f);
      continue;
    }
    if (*i<249) return -1;
    if (*i<=252) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<253) return -1;
    if (*i==253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016d>>6);
      *o++ = 0x80 | (0x016d&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015d>>6);
      *o++ = 0x80 | (0x015d&0x3f);
      continue;
    }
    if (*i<255) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02d9>>6);
      *o++ = 0x80 | (0x02d9&0x3f);
      continue;
    }
    return -1;
  }
  if (end-o < 1) return -2;
  *o++ = 0;
  return 0;
}

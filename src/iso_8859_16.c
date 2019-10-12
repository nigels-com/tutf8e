#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_16_utf8(char *dest, size_t size, const char *src)
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
      if (end-o < 2) return -2;
      uint16_t v = 0x0104 + *i - 161u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<163) return -1;
    if (*i==163) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0141>>6);
      *o++ = 0x80 | (0x0141&0x3f);
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
      *o++ = 0xe0 | (0x201e>>12);
      *o++ = 0x80 | ((0x201e>>6)&0x3f);
      *o++ = 0x80 | (0x201e&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i==166) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0160>>6);
      *o++ = 0x80 | (0x0160&0x3f);
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
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0161>>6);
      *o++ = 0x80 | (0x0161&0x3f);
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
      *o++ = 0xc0 | (0x0218>>6);
      *o++ = 0x80 | (0x0218&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i==171) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ab>>6);
      *o++ = 0x80 | (0x00ab&0x3f);
      continue;
    }
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0179>>6);
      *o++ = 0x80 | (0x0179&0x3f);
      continue;
    }
    if (*i<173) return -1;
    if (*i==173) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ad>>6);
      *o++ = 0x80 | (0x00ad&0x3f);
      continue;
    }
    if (*i<174) return -1;
    if (*i<=175) {
      if (end-o < 2) return -2;
      uint16_t v = 0x017a + *i - 174u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
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
      *o++ = 0xc0 | (0x010c>>6);
      *o++ = 0x80 | (0x010c&0x3f);
      continue;
    }
    if (*i<179) return -1;
    if (*i==179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0142>>6);
      *o++ = 0x80 | (0x0142&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i==180) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017d>>6);
      *o++ = 0x80 | (0x017d&0x3f);
      continue;
    }
    if (*i<181) return -1;
    if (*i==181) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x201d>>12);
      *o++ = 0x80 | ((0x201d>>6)&0x3f);
      *o++ = 0x80 | (0x201d&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i<=183) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<184) return -1;
    if (*i==184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017e>>6);
      *o++ = 0x80 | (0x017e&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i==185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010d>>6);
      *o++ = 0x80 | (0x010d&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0219>>6);
      *o++ = 0x80 | (0x0219&0x3f);
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
    if (*i<=189) {
      if (end-o < 2) return -2;
      uint16_t v = 0x0152 + *i - 188u;
      *o++ = 0xc0 | (v>>6);
      *o++ = 0x80 | (v&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i==190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0178>>6);
      *o++ = 0x80 | (0x0178&0x3f);
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
    if (*i<195) return -1;
    if (*i==195) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0102>>6);
      *o++ = 0x80 | (0x0102&0x3f);
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
      *o++ = 0xc0 | (0x0106>>6);
      *o++ = 0x80 | (0x0106&0x3f);
      continue;
    }
    if (*i<198) return -1;
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
      *o++ = 0xc0 | (0x0143>>6);
      *o++ = 0x80 | (0x0143&0x3f);
      continue;
    }
    if (*i<210) return -1;
    if (*i<=212) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<213) return -1;
    if (*i==213) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0150>>6);
      *o++ = 0x80 | (0x0150&0x3f);
      continue;
    }
    if (*i<214) return -1;
    if (*i==214) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d6>>6);
      *o++ = 0x80 | (0x00d6&0x3f);
      continue;
    }
    if (*i<215) return -1;
    if (*i==215) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015a>>6);
      *o++ = 0x80 | (0x015a&0x3f);
      continue;
    }
    if (*i<216) return -1;
    if (*i==216) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0170>>6);
      *o++ = 0x80 | (0x0170&0x3f);
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
      *o++ = 0xc0 | (0x0118>>6);
      *o++ = 0x80 | (0x0118&0x3f);
      continue;
    }
    if (*i<222) return -1;
    if (*i==222) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x021a>>6);
      *o++ = 0x80 | (0x021a&0x3f);
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
    if (*i==228) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e4>>6);
      *o++ = 0x80 | (0x00e4&0x3f);
      continue;
    }
    if (*i<229) return -1;
    if (*i==229) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0107>>6);
      *o++ = 0x80 | (0x0107&0x3f);
      continue;
    }
    if (*i<230) return -1;
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
      *o++ = 0xc0 | (0x0144>>6);
      *o++ = 0x80 | (0x0144&0x3f);
      continue;
    }
    if (*i<242) return -1;
    if (*i<=244) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<245) return -1;
    if (*i==245) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0151>>6);
      *o++ = 0x80 | (0x0151&0x3f);
      continue;
    }
    if (*i<246) return -1;
    if (*i==246) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f6>>6);
      *o++ = 0x80 | (0x00f6&0x3f);
      continue;
    }
    if (*i<247) return -1;
    if (*i==247) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015b>>6);
      *o++ = 0x80 | (0x015b&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i==248) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0171>>6);
      *o++ = 0x80 | (0x0171&0x3f);
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
      *o++ = 0xc0 | (0x0119>>6);
      *o++ = 0x80 | (0x0119&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x021b>>6);
      *o++ = 0x80 | (0x021b&0x3f);
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

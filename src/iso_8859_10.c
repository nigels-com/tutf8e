#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_10_utf8(char *dest, size_t size, const char *src)
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
      *o++ = 0xc0 | (0x0104>>6);
      *o++ = 0x80 | (0x0104&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i==162) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0112>>6);
      *o++ = 0x80 | (0x0112&0x3f);
      continue;
    }
    if (*i<163) return -1;
    if (*i==163) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0122>>6);
      *o++ = 0x80 | (0x0122&0x3f);
      continue;
    }
    if (*i<164) return -1;
    if (*i==164) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012a>>6);
      *o++ = 0x80 | (0x012a&0x3f);
      continue;
    }
    if (*i<165) return -1;
    if (*i==165) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0128>>6);
      *o++ = 0x80 | (0x0128&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i==166) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0136>>6);
      *o++ = 0x80 | (0x0136&0x3f);
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
      *o++ = 0xc0 | (0x013b>>6);
      *o++ = 0x80 | (0x013b&0x3f);
      continue;
    }
    if (*i<169) return -1;
    if (*i==169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0110>>6);
      *o++ = 0x80 | (0x0110&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0160>>6);
      *o++ = 0x80 | (0x0160&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i==171) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0166>>6);
      *o++ = 0x80 | (0x0166&0x3f);
      continue;
    }
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017d>>6);
      *o++ = 0x80 | (0x017d&0x3f);
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
    if (*i==174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016a>>6);
      *o++ = 0x80 | (0x016a&0x3f);
      continue;
    }
    if (*i<175) return -1;
    if (*i==175) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x014a>>6);
      *o++ = 0x80 | (0x014a&0x3f);
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
      *o++ = 0xc0 | (0x0105>>6);
      *o++ = 0x80 | (0x0105&0x3f);
      continue;
    }
    if (*i<178) return -1;
    if (*i==178) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0113>>6);
      *o++ = 0x80 | (0x0113&0x3f);
      continue;
    }
    if (*i<179) return -1;
    if (*i==179) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0123>>6);
      *o++ = 0x80 | (0x0123&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i==180) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012b>>6);
      *o++ = 0x80 | (0x012b&0x3f);
      continue;
    }
    if (*i<181) return -1;
    if (*i==181) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0129>>6);
      *o++ = 0x80 | (0x0129&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i==182) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0137>>6);
      *o++ = 0x80 | (0x0137&0x3f);
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
    if (*i==184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013c>>6);
      *o++ = 0x80 | (0x013c&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i==185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0111>>6);
      *o++ = 0x80 | (0x0111&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0161>>6);
      *o++ = 0x80 | (0x0161&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i==187) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0167>>6);
      *o++ = 0x80 | (0x0167&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017e>>6);
      *o++ = 0x80 | (0x017e&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2015>>12);
      *o++ = 0x80 | ((0x2015>>6)&0x3f);
      *o++ = 0x80 | (0x2015&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i==190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016b>>6);
      *o++ = 0x80 | (0x016b&0x3f);
      continue;
    }
    if (*i<191) return -1;
    if (*i==191) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x014b>>6);
      *o++ = 0x80 | (0x014b&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0100>>6);
      *o++ = 0x80 | (0x0100&0x3f);
      continue;
    }
    if (*i<193) return -1;
    if (*i<=198) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<199) return -1;
    if (*i==199) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012e>>6);
      *o++ = 0x80 | (0x012e&0x3f);
      continue;
    }
    if (*i<200) return -1;
    if (*i==200) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010c>>6);
      *o++ = 0x80 | (0x010c&0x3f);
      continue;
    }
    if (*i<201) return -1;
    if (*i==201) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00c9>>6);
      *o++ = 0x80 | (0x00c9&0x3f);
      continue;
    }
    if (*i<202) return -1;
    if (*i==202) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0118>>6);
      *o++ = 0x80 | (0x0118&0x3f);
      continue;
    }
    if (*i<203) return -1;
    if (*i==203) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00cb>>6);
      *o++ = 0x80 | (0x00cb&0x3f);
      continue;
    }
    if (*i<204) return -1;
    if (*i==204) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0116>>6);
      *o++ = 0x80 | (0x0116&0x3f);
      continue;
    }
    if (*i<205) return -1;
    if (*i<=208) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<209) return -1;
    if (*i==209) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0145>>6);
      *o++ = 0x80 | (0x0145&0x3f);
      continue;
    }
    if (*i<210) return -1;
    if (*i==210) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x014c>>6);
      *o++ = 0x80 | (0x014c&0x3f);
      continue;
    }
    if (*i<211) return -1;
    if (*i<=214) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<215) return -1;
    if (*i==215) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0168>>6);
      *o++ = 0x80 | (0x0168&0x3f);
      continue;
    }
    if (*i<216) return -1;
    if (*i==216) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d8>>6);
      *o++ = 0x80 | (0x00d8&0x3f);
      continue;
    }
    if (*i<217) return -1;
    if (*i==217) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0172>>6);
      *o++ = 0x80 | (0x0172&0x3f);
      continue;
    }
    if (*i<218) return -1;
    if (*i<=223) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<224) return -1;
    if (*i==224) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0101>>6);
      *o++ = 0x80 | (0x0101&0x3f);
      continue;
    }
    if (*i<225) return -1;
    if (*i<=230) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<231) return -1;
    if (*i==231) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012f>>6);
      *o++ = 0x80 | (0x012f&0x3f);
      continue;
    }
    if (*i<232) return -1;
    if (*i==232) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010d>>6);
      *o++ = 0x80 | (0x010d&0x3f);
      continue;
    }
    if (*i<233) return -1;
    if (*i==233) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e9>>6);
      *o++ = 0x80 | (0x00e9&0x3f);
      continue;
    }
    if (*i<234) return -1;
    if (*i==234) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0119>>6);
      *o++ = 0x80 | (0x0119&0x3f);
      continue;
    }
    if (*i<235) return -1;
    if (*i==235) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00eb>>6);
      *o++ = 0x80 | (0x00eb&0x3f);
      continue;
    }
    if (*i<236) return -1;
    if (*i==236) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0117>>6);
      *o++ = 0x80 | (0x0117&0x3f);
      continue;
    }
    if (*i<237) return -1;
    if (*i<=240) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i==241) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0146>>6);
      *o++ = 0x80 | (0x0146&0x3f);
      continue;
    }
    if (*i<242) return -1;
    if (*i==242) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x014d>>6);
      *o++ = 0x80 | (0x014d&0x3f);
      continue;
    }
    if (*i<243) return -1;
    if (*i<=246) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<247) return -1;
    if (*i==247) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0169>>6);
      *o++ = 0x80 | (0x0169&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i==248) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f8>>6);
      *o++ = 0x80 | (0x00f8&0x3f);
      continue;
    }
    if (*i<249) return -1;
    if (*i==249) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0173>>6);
      *o++ = 0x80 | (0x0173&0x3f);
      continue;
    }
    if (*i<250) return -1;
    if (*i<=254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<255) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0138>>6);
      *o++ = 0x80 | (0x0138&0x3f);
      continue;
    }
    return -1;
  }
  if (end-o < 1) return -2;
  *o++ = 0;
  return 0;
}

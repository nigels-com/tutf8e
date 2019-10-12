#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_2_utf8(char *dest, size_t size, const char *src)
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
      *o++ = 0xc0 | (0x02d8>>6);
      *o++ = 0x80 | (0x02d8&0x3f);
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
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a4>>6);
      *o++ = 0x80 | (0x00a4&0x3f);
      continue;
    }
    if (*i<165) return -1;
    if (*i==165) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013d>>6);
      *o++ = 0x80 | (0x013d&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i==166) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015a>>6);
      *o++ = 0x80 | (0x015a&0x3f);
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
      *o++ = 0xc0 | (0x0160>>6);
      *o++ = 0x80 | (0x0160&0x3f);
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
      *o++ = 0xc0 | (0x0164>>6);
      *o++ = 0x80 | (0x0164&0x3f);
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
    if (*i==174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017d>>6);
      *o++ = 0x80 | (0x017d&0x3f);
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
      *o++ = 0xc0 | (0x0105>>6);
      *o++ = 0x80 | (0x0105&0x3f);
      continue;
    }
    if (*i<178) return -1;
    if (*i==178) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02db>>6);
      *o++ = 0x80 | (0x02db&0x3f);
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
      *o++ = 0xc0 | (0x00b4>>6);
      *o++ = 0x80 | (0x00b4&0x3f);
      continue;
    }
    if (*i<181) return -1;
    if (*i==181) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013e>>6);
      *o++ = 0x80 | (0x013e&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i==182) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015b>>6);
      *o++ = 0x80 | (0x015b&0x3f);
      continue;
    }
    if (*i<183) return -1;
    if (*i==183) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02c7>>6);
      *o++ = 0x80 | (0x02c7&0x3f);
      continue;
    }
    if (*i<184) return -1;
    if (*i==184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b8>>6);
      *o++ = 0x80 | (0x00b8&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i==185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0161>>6);
      *o++ = 0x80 | (0x0161&0x3f);
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
      *o++ = 0xc0 | (0x0165>>6);
      *o++ = 0x80 | (0x0165&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017a>>6);
      *o++ = 0x80 | (0x017a&0x3f);
      continue;
    }
    if (*i<189) return -1;
    if (*i==189) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02dd>>6);
      *o++ = 0x80 | (0x02dd&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i==190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017e>>6);
      *o++ = 0x80 | (0x017e&0x3f);
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
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0154>>6);
      *o++ = 0x80 | (0x0154&0x3f);
      continue;
    }
    if (*i<193) return -1;
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
      *o++ = 0xc0 | (0x0139>>6);
      *o++ = 0x80 | (0x0139&0x3f);
      continue;
    }
    if (*i<198) return -1;
    if (*i==198) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0106>>6);
      *o++ = 0x80 | (0x0106&0x3f);
      continue;
    }
    if (*i<199) return -1;
    if (*i==199) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00c7>>6);
      *o++ = 0x80 | (0x00c7&0x3f);
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
      *o++ = 0xc0 | (0x011a>>6);
      *o++ = 0x80 | (0x011a&0x3f);
      continue;
    }
    if (*i<205) return -1;
    if (*i<=206) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<207) return -1;
    if (*i==207) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010e>>6);
      *o++ = 0x80 | (0x010e&0x3f);
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
    if (*i==210) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0147>>6);
      *o++ = 0x80 | (0x0147&0x3f);
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
      *o++ = 0xc0 | (0x0150>>6);
      *o++ = 0x80 | (0x0150&0x3f);
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
      *o++ = 0xc0 | (0x0158>>6);
      *o++ = 0x80 | (0x0158&0x3f);
      continue;
    }
    if (*i<217) return -1;
    if (*i==217) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016e>>6);
      *o++ = 0x80 | (0x016e&0x3f);
      continue;
    }
    if (*i<218) return -1;
    if (*i==218) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00da>>6);
      *o++ = 0x80 | (0x00da&0x3f);
      continue;
    }
    if (*i<219) return -1;
    if (*i==219) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0170>>6);
      *o++ = 0x80 | (0x0170&0x3f);
      continue;
    }
    if (*i<220) return -1;
    if (*i<=221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<222) return -1;
    if (*i==222) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0162>>6);
      *o++ = 0x80 | (0x0162&0x3f);
      continue;
    }
    if (*i<223) return -1;
    if (*i==223) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00df>>6);
      *o++ = 0x80 | (0x00df&0x3f);
      continue;
    }
    if (*i<224) return -1;
    if (*i==224) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0155>>6);
      *o++ = 0x80 | (0x0155&0x3f);
      continue;
    }
    if (*i<225) return -1;
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
      *o++ = 0xc0 | (0x013a>>6);
      *o++ = 0x80 | (0x013a&0x3f);
      continue;
    }
    if (*i<230) return -1;
    if (*i==230) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0107>>6);
      *o++ = 0x80 | (0x0107&0x3f);
      continue;
    }
    if (*i<231) return -1;
    if (*i==231) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e7>>6);
      *o++ = 0x80 | (0x00e7&0x3f);
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
      *o++ = 0xc0 | (0x011b>>6);
      *o++ = 0x80 | (0x011b&0x3f);
      continue;
    }
    if (*i<237) return -1;
    if (*i<=238) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<239) return -1;
    if (*i==239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010f>>6);
      *o++ = 0x80 | (0x010f&0x3f);
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
    if (*i==242) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0148>>6);
      *o++ = 0x80 | (0x0148&0x3f);
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
      *o++ = 0xc0 | (0x0151>>6);
      *o++ = 0x80 | (0x0151&0x3f);
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
      *o++ = 0xc0 | (0x0159>>6);
      *o++ = 0x80 | (0x0159&0x3f);
      continue;
    }
    if (*i<249) return -1;
    if (*i==249) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016f>>6);
      *o++ = 0x80 | (0x016f&0x3f);
      continue;
    }
    if (*i<250) return -1;
    if (*i==250) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00fa>>6);
      *o++ = 0x80 | (0x00fa&0x3f);
      continue;
    }
    if (*i<251) return -1;
    if (*i==251) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0171>>6);
      *o++ = 0x80 | (0x0171&0x3f);
      continue;
    }
    if (*i<252) return -1;
    if (*i<=253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0163>>6);
      *o++ = 0x80 | (0x0163&0x3f);
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

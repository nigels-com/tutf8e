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
    if (*i<129) return -1;
    if (*i<=160) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i==162) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02d8>>6);
      *o++ = 0x80 | (0x02d8&0x3f);
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
    if (*i==166) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015a>>6);
      *o++ = 0x80 | (0x015a&0x3f);
      continue;
    }
    if (*i<168) return -1;
    if (*i==168) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a8>>6);
      *o++ = 0x80 | (0x00a8&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015e>>6);
      *o++ = 0x80 | (0x015e&0x3f);
      continue;
    }
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0179>>6);
      *o++ = 0x80 | (0x0179&0x3f);
      continue;
    }
    if (*i<174) return -1;
    if (*i==174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017d>>6);
      *o++ = 0x80 | (0x017d&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i==176) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b0>>6);
      *o++ = 0x80 | (0x00b0&0x3f);
      continue;
    }
    if (*i<178) return -1;
    if (*i==178) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02db>>6);
      *o++ = 0x80 | (0x02db&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i==180) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b4>>6);
      *o++ = 0x80 | (0x00b4&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i==182) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015b>>6);
      *o++ = 0x80 | (0x015b&0x3f);
      continue;
    }
    if (*i<184) return -1;
    if (*i==184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b8>>6);
      *o++ = 0x80 | (0x00b8&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015f>>6);
      *o++ = 0x80 | (0x015f&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017a>>6);
      *o++ = 0x80 | (0x017a&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i==190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017e>>6);
      *o++ = 0x80 | (0x017e&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0154>>6);
      *o++ = 0x80 | (0x0154&0x3f);
      continue;
    }
    if (*i<194) return -1;
    if (*i==194) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00c2>>6);
      *o++ = 0x80 | (0x00c2&0x3f);
      continue;
    }
    if (*i<196) return -1;
    if (*i==196) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00c4>>6);
      *o++ = 0x80 | (0x00c4&0x3f);
      continue;
    }
    if (*i<198) return -1;
    if (*i==198) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0106>>6);
      *o++ = 0x80 | (0x0106&0x3f);
      continue;
    }
    if (*i<200) return -1;
    if (*i==200) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010c>>6);
      *o++ = 0x80 | (0x010c&0x3f);
      continue;
    }
    if (*i<202) return -1;
    if (*i==202) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0118>>6);
      *o++ = 0x80 | (0x0118&0x3f);
      continue;
    }
    if (*i<204) return -1;
    if (*i==204) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011a>>6);
      *o++ = 0x80 | (0x011a&0x3f);
      continue;
    }
    if (*i<206) return -1;
    if (*i==206) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ce>>6);
      *o++ = 0x80 | (0x00ce&0x3f);
      continue;
    }
    if (*i<208) return -1;
    if (*i==208) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0110>>6);
      *o++ = 0x80 | (0x0110&0x3f);
      continue;
    }
    if (*i<210) return -1;
    if (*i==210) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0147>>6);
      *o++ = 0x80 | (0x0147&0x3f);
      continue;
    }
    if (*i<212) return -1;
    if (*i==212) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d4>>6);
      *o++ = 0x80 | (0x00d4&0x3f);
      continue;
    }
    if (*i<214) return -1;
    if (*i<=215) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<217) return -1;
    if (*i==217) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016e>>6);
      *o++ = 0x80 | (0x016e&0x3f);
      continue;
    }
    if (*i<219) return -1;
    if (*i==219) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0170>>6);
      *o++ = 0x80 | (0x0170&0x3f);
      continue;
    }
    if (*i<221) return -1;
    if (*i==221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00dd>>6);
      *o++ = 0x80 | (0x00dd&0x3f);
      continue;
    }
    if (*i<223) return -1;
    if (*i==223) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00df>>6);
      *o++ = 0x80 | (0x00df&0x3f);
      continue;
    }
    if (*i<225) return -1;
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
    if (*i<230) return -1;
    if (*i==230) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0107>>6);
      *o++ = 0x80 | (0x0107&0x3f);
      continue;
    }
    if (*i<232) return -1;
    if (*i==232) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x010d>>6);
      *o++ = 0x80 | (0x010d&0x3f);
      continue;
    }
    if (*i<234) return -1;
    if (*i==234) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0119>>6);
      *o++ = 0x80 | (0x0119&0x3f);
      continue;
    }
    if (*i<236) return -1;
    if (*i==236) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011b>>6);
      *o++ = 0x80 | (0x011b&0x3f);
      continue;
    }
    if (*i<238) return -1;
    if (*i==238) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ee>>6);
      *o++ = 0x80 | (0x00ee&0x3f);
      continue;
    }
    if (*i<240) return -1;
    if (*i==240) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0111>>6);
      *o++ = 0x80 | (0x0111&0x3f);
      continue;
    }
    if (*i<242) return -1;
    if (*i==242) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0148>>6);
      *o++ = 0x80 | (0x0148&0x3f);
      continue;
    }
    if (*i<244) return -1;
    if (*i==244) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f4>>6);
      *o++ = 0x80 | (0x00f4&0x3f);
      continue;
    }
    if (*i<246) return -1;
    if (*i<=247) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<249) return -1;
    if (*i==249) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016f>>6);
      *o++ = 0x80 | (0x016f&0x3f);
      continue;
    }
    if (*i<251) return -1;
    if (*i==251) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0171>>6);
      *o++ = 0x80 | (0x0171&0x3f);
      continue;
    }
    if (*i<253) return -1;
    if (*i==253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00fd>>6);
      *o++ = 0x80 | (0x00fd&0x3f);
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
  return 0;
}

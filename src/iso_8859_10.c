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
      *o++ = 0xc0 | (0x0112>>6);
      *o++ = 0x80 | (0x0112&0x3f);
      continue;
    }
    if (*i<164) return -1;
    if (*i==164) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012a>>6);
      *o++ = 0x80 | (0x012a&0x3f);
      continue;
    }
    if (*i<166) return -1;
    if (*i==166) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0136>>6);
      *o++ = 0x80 | (0x0136&0x3f);
      continue;
    }
    if (*i<168) return -1;
    if (*i==168) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013b>>6);
      *o++ = 0x80 | (0x013b&0x3f);
      continue;
    }
    if (*i<170) return -1;
    if (*i==170) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0160>>6);
      *o++ = 0x80 | (0x0160&0x3f);
      continue;
    }
    if (*i<172) return -1;
    if (*i==172) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017d>>6);
      *o++ = 0x80 | (0x017d&0x3f);
      continue;
    }
    if (*i<174) return -1;
    if (*i==174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016a>>6);
      *o++ = 0x80 | (0x016a&0x3f);
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
      *o++ = 0xc0 | (0x0113>>6);
      *o++ = 0x80 | (0x0113&0x3f);
      continue;
    }
    if (*i<180) return -1;
    if (*i==180) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012b>>6);
      *o++ = 0x80 | (0x012b&0x3f);
      continue;
    }
    if (*i<182) return -1;
    if (*i==182) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0137>>6);
      *o++ = 0x80 | (0x0137&0x3f);
      continue;
    }
    if (*i<184) return -1;
    if (*i==184) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013c>>6);
      *o++ = 0x80 | (0x013c&0x3f);
      continue;
    }
    if (*i<186) return -1;
    if (*i==186) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0161>>6);
      *o++ = 0x80 | (0x0161&0x3f);
      continue;
    }
    if (*i<188) return -1;
    if (*i==188) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017e>>6);
      *o++ = 0x80 | (0x017e&0x3f);
      continue;
    }
    if (*i<190) return -1;
    if (*i==190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016b>>6);
      *o++ = 0x80 | (0x016b&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0100>>6);
      *o++ = 0x80 | (0x0100&0x3f);
      continue;
    }
    if (*i<194) return -1;
    if (*i<=198) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
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
      *o++ = 0xc0 | (0x0116>>6);
      *o++ = 0x80 | (0x0116&0x3f);
      continue;
    }
    if (*i<206) return -1;
    if (*i<=208) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<210) return -1;
    if (*i==210) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x014c>>6);
      *o++ = 0x80 | (0x014c&0x3f);
      continue;
    }
    if (*i<212) return -1;
    if (*i<=214) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<216) return -1;
    if (*i==216) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d8>>6);
      *o++ = 0x80 | (0x00d8&0x3f);
      continue;
    }
    if (*i<218) return -1;
    if (*i<=223) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<225) return -1;
    if (*i<=230) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
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
      *o++ = 0xc0 | (0x0117>>6);
      *o++ = 0x80 | (0x0117&0x3f);
      continue;
    }
    if (*i<238) return -1;
    if (*i<=240) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<242) return -1;
    if (*i==242) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x014d>>6);
      *o++ = 0x80 | (0x014d&0x3f);
      continue;
    }
    if (*i<244) return -1;
    if (*i<=246) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<248) return -1;
    if (*i==248) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f8>>6);
      *o++ = 0x80 | (0x00f8&0x3f);
      continue;
    }
    if (*i<250) return -1;
    if (*i<=254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    return -1;
  }
  return 0;
}

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_windows_1257_utf8(char *dest, size_t size, const char *src)
{
  unsigned char *o = (unsigned char *) dest;
  unsigned char *end = dest + size;
  for (const unsigned char *i = (unsigned char *) src; *i; ++i) {
    if (*i<=127) {
      if (end-o < 1) return -2;
      *o++ = *i;
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
    if (*i<133) return -1;
    if (*i==133) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2026>>12);
      *o++ = 0x80 | ((0x2026>>6)&0x3f);
      *o++ = 0x80 | (0x2026&0x3f);
      continue;
    }
    if (*i<135) return -1;
    if (*i==135) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x2021>>12);
      *o++ = 0x80 | ((0x2021>>6)&0x3f);
      *o++ = 0x80 | (0x2021&0x3f);
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
    if (*i<142) return -1;
    if (*i==142) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02c7>>6);
      *o++ = 0x80 | (0x02c7&0x3f);
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
    if (*i<148) return -1;
    if (*i==148) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x201d>>12);
      *o++ = 0x80 | ((0x201d>>6)&0x3f);
      *o++ = 0x80 | (0x201d&0x3f);
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
    if (*i<155) return -1;
    if (*i==155) {
      if (end-o < 3) return -2;
      *o++ = 0xe0 | (0x203a>>12);
      *o++ = 0x80 | ((0x203a>>6)&0x3f);
      *o++ = 0x80 | (0x203a&0x3f);
      continue;
    }
    if (*i<158) return -1;
    if (*i==158) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x02db>>6);
      *o++ = 0x80 | (0x02db&0x3f);
      continue;
    }
    if (*i<162) return -1;
    if (*i<=164) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<167) return -1;
    if (*i==167) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a7>>6);
      *o++ = 0x80 | (0x00a7&0x3f);
      continue;
    }
    if (*i<169) return -1;
    if (*i==169) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00a9>>6);
      *o++ = 0x80 | (0x00a9&0x3f);
      continue;
    }
    if (*i<171) return -1;
    if (*i<=174) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<176) return -1;
    if (*i<=183) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<185) return -1;
    if (*i==185) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00b9>>6);
      *o++ = 0x80 | (0x00b9&0x3f);
      continue;
    }
    if (*i<187) return -1;
    if (*i<=190) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<192) return -1;
    if (*i==192) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0104>>6);
      *o++ = 0x80 | (0x0104&0x3f);
      continue;
    }
    if (*i<194) return -1;
    if (*i==194) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0100>>6);
      *o++ = 0x80 | (0x0100&0x3f);
      continue;
    }
    if (*i<196) return -1;
    if (*i<=197) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<199) return -1;
    if (*i==199) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0112>>6);
      *o++ = 0x80 | (0x0112&0x3f);
      continue;
    }
    if (*i<201) return -1;
    if (*i==201) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00c9>>6);
      *o++ = 0x80 | (0x00c9&0x3f);
      continue;
    }
    if (*i<203) return -1;
    if (*i==203) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0116>>6);
      *o++ = 0x80 | (0x0116&0x3f);
      continue;
    }
    if (*i<205) return -1;
    if (*i==205) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0136>>6);
      *o++ = 0x80 | (0x0136&0x3f);
      continue;
    }
    if (*i<207) return -1;
    if (*i==207) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013b>>6);
      *o++ = 0x80 | (0x013b&0x3f);
      continue;
    }
    if (*i<209) return -1;
    if (*i==209) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0143>>6);
      *o++ = 0x80 | (0x0143&0x3f);
      continue;
    }
    if (*i<211) return -1;
    if (*i==211) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00d3>>6);
      *o++ = 0x80 | (0x00d3&0x3f);
      continue;
    }
    if (*i<213) return -1;
    if (*i<=215) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<217) return -1;
    if (*i==217) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0141>>6);
      *o++ = 0x80 | (0x0141&0x3f);
      continue;
    }
    if (*i<219) return -1;
    if (*i==219) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016a>>6);
      *o++ = 0x80 | (0x016a&0x3f);
      continue;
    }
    if (*i<221) return -1;
    if (*i==221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017b>>6);
      *o++ = 0x80 | (0x017b&0x3f);
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
    if (*i==225) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x012f>>6);
      *o++ = 0x80 | (0x012f&0x3f);
      continue;
    }
    if (*i<227) return -1;
    if (*i==227) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0107>>6);
      *o++ = 0x80 | (0x0107&0x3f);
      continue;
    }
    if (*i<229) return -1;
    if (*i==229) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e5>>6);
      *o++ = 0x80 | (0x00e5&0x3f);
      continue;
    }
    if (*i<231) return -1;
    if (*i==231) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0113>>6);
      *o++ = 0x80 | (0x0113&0x3f);
      continue;
    }
    if (*i<233) return -1;
    if (*i==233) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00e9>>6);
      *o++ = 0x80 | (0x00e9&0x3f);
      continue;
    }
    if (*i<235) return -1;
    if (*i==235) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0117>>6);
      *o++ = 0x80 | (0x0117&0x3f);
      continue;
    }
    if (*i<237) return -1;
    if (*i==237) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0137>>6);
      *o++ = 0x80 | (0x0137&0x3f);
      continue;
    }
    if (*i<239) return -1;
    if (*i==239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x013c>>6);
      *o++ = 0x80 | (0x013c&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i==241) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0144>>6);
      *o++ = 0x80 | (0x0144&0x3f);
      continue;
    }
    if (*i<243) return -1;
    if (*i==243) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00f3>>6);
      *o++ = 0x80 | (0x00f3&0x3f);
      continue;
    }
    if (*i<245) return -1;
    if (*i<=247) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<249) return -1;
    if (*i==249) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0142>>6);
      *o++ = 0x80 | (0x0142&0x3f);
      continue;
    }
    if (*i<251) return -1;
    if (*i==251) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x016b>>6);
      *o++ = 0x80 | (0x016b&0x3f);
      continue;
    }
    if (*i<253) return -1;
    if (*i==253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x017c>>6);
      *o++ = 0x80 | (0x017c&0x3f);
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


#include <tutf8e.h>

#include <sys/errno.h>

/* Determine the length of the UTF8 encoding of given input string and table */
/* return ENOENT if input character is not convertable                       */
/* return 0 for success                                                      */

int length_utf8(const uint16_t *table, const char **ibuf, size_t *ileft, size_t *length)
{
  size_t len = 0;
  for (const unsigned char **i = (const unsigned char **) ibuf; *ileft; *i += 1, *ileft -= 1) {
    const uint16_t c = table[**i];
    if (c<0x80) {
      ++*length;
      continue;
    }
    if (c<0x800) {
      *length += 2;
      continue;
    }
    if (c<0xffff) {
      *length += 3;
      continue;
    }
    return ENOENT;
  }
  return 0;
}

/* UTF8 encode the given input string and table        */
/* return E2BIG if output buffer insuficient           */
/* return ENOENT if input character is not convertable */
/* return 0 for success                                */

int encode_utf8(const uint16_t *table, const char **ibuf, size_t *ileft, char **obuf, size_t *oleft)
{
  unsigned char **o = (unsigned char **) obuf;
  for (const unsigned char **i = (const unsigned char **) ibuf; *ileft; *i += 1, *ileft -= 1) {
    const uint16_t c = table[**i];
    if (c<0x80) {
      if (*oleft<1) return E2BIG;
      *((*o)++) = c;
      *oleft -= 1;
      continue;
    }
    if (c<0x800) {
      if (*oleft<2) return E2BIG;
      *((*o)++) = 0xc0 | (c>>6);
      *((*o)++) = 0x80 | (c&0x3f);
      *oleft -= 2;
      continue;
    }
    if (c<0xffff) {
      if (*oleft<3) return E2BIG;
      *((*o)++) = 0xe0 | (c>>12);
      *((*o)++) = 0x80 | ((c>>6)&0x3f);
      *((*o)++) = 0x80 | (c&0x3f);
      *oleft -= 3;
      continue;
    }
    return ENOENT;
  }
  return 0;
}

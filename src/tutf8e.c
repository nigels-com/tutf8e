
#include <tutf8e.h>

#include <sys/errno.h>

/* Determine the length of the UTF8 encoding of given input string and table */
/* return ENOENT if input character is not convertable                       */
/* return 0 for success                                                      */

int tutf8e_buffer_length(const uint16_t *table, const char *input, size_t ilen, size_t *length)
{
  for (const unsigned char *i = (const unsigned char *) input; ilen; ++i, --ilen) {
    const uint16_t c = table[*i];
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

int tutf8e_buffer_encode(const uint16_t *table, const char *input, size_t ilen, char *output, size_t olen)
{
  unsigned char *o = (unsigned char *) output;
  for (const unsigned char *i = (const unsigned char *) input; ilen; ++i, --ilen) {
    const uint16_t c = table[*i];
    if (c<0x80) {
      if (olen<1) return E2BIG;
      *(o++) = c;
      olen -= 1;
      continue;
    }
    if (c<0x800) {
      if (olen<2) return E2BIG;
      *(o++) = 0xc0 | (c>>6);
      *(o++) = 0x80 | (c&0x3f);
      olen -= 2;
      continue;
    }
    if (c<0xffff) {
      if (olen<3) return E2BIG;
      *(o++) = 0xe0 | (c>>12);
      *(o++) = 0x80 | ((c>>6)&0x3f);
      *(o++) = 0x80 | (c&0x3f);
      olen -= 3;
      continue;
    }
    return ENOENT;
  }
  return 0;
}

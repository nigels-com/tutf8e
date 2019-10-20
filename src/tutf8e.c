
#include <tutf8e.h>

/* Determine the input length and UTF8 encoded length of NUL-terminated input string */
/* return TUTF8E_INVALID if input character is not convertable                       */
/* return TUTF8E_OK for success                                                      */

int tutf8e_string_length(const uint16_t *table, const char *input, size_t *ilen, size_t *olen)
{
  for (const unsigned char *i = (const unsigned char *) input; *i; ++i, (*ilen)++) {
    const uint16_t c = table[*i];
    if (c<0x80) {
      *olen += 1;
      continue;
    }
    if (c<0x800) {
      *olen += 2;
      continue;
    }
    if (c<0xffff) {
      *olen += 3;
      continue;
    }
    return TUTF8E_INVALID;
  }
  return TUTF8E_OK;
}

/* Determine the length of the UTF8 encoding of given input string and table */
/* return TUTF8E_INVALID if input character is not convertable               */
/* return TUTF8E_OK for success                                              */

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
    return TUTF8E_INVALID;
  }
  return TUTF8E_OK;
}

/* UTF8 encode the given input string and table                */
/* olen input is output buffer size, output is encoded length  */
/* return TUTF8E_TOOLONG if output buffer insuficient          */
/* return TUTF8E_INVALID if input character is not convertable */
/* return TUTF8E_OK for success                                */

int tutf8e_buffer_encode(const uint16_t *table, const char *input, size_t ilen, char *output, size_t *olen)
{
  size_t left = *olen;
  unsigned char *o = (unsigned char *) output;
  for (const unsigned char *i = (const unsigned char *) input; ilen; ++i, --ilen) {
    const uint16_t c = table[*i];
    if (c<0x80) {
      if (left<1) return TUTF8E_TOOLONG;
      *(o++) = c;
      left -= 1;
      continue;
    }
    if (c<0x800) {
      if (left<2) return TUTF8E_TOOLONG;
      *(o++) = 0xc0 | (c>>6);
      *(o++) = 0x80 | (c&0x3f);
      left -= 2;
      continue;
    }
    if (c<0xffff) {
      if (left<3) return TUTF8E_TOOLONG;
      *(o++) = 0xe0 | (c>>12);
      *(o++) = 0x80 | ((c>>6)&0x3f);
      *(o++) = 0x80 | (c&0x3f);
      left -= 3;
      continue;
    }
    return TUTF8E_INVALID;
  }
  *olen -= left;
  return TUTF8E_OK;
}

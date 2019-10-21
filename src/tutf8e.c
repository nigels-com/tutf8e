
#include <tutf8e.h>

#include <string.h>

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

TUTF8encoder tutf8e_encoder(const char *encoding)
{
  if (!strcmp(encoding, "iso-8859-1")) return (TUTF8encoder) tutf8e_iso_8859_1_utf8;
  if (!strcmp(encoding, "iso-8859-10")) return (TUTF8encoder) tutf8e_iso_8859_10_utf8;
  if (!strcmp(encoding, "iso-8859-11")) return (TUTF8encoder) tutf8e_iso_8859_11_utf8;
  if (!strcmp(encoding, "iso-8859-13")) return (TUTF8encoder) tutf8e_iso_8859_13_utf8;
  if (!strcmp(encoding, "iso-8859-14")) return (TUTF8encoder) tutf8e_iso_8859_14_utf8;
  if (!strcmp(encoding, "iso-8859-15")) return (TUTF8encoder) tutf8e_iso_8859_15_utf8;
  if (!strcmp(encoding, "iso-8859-16")) return (TUTF8encoder) tutf8e_iso_8859_16_utf8;
  if (!strcmp(encoding, "iso-8859-2")) return (TUTF8encoder) tutf8e_iso_8859_2_utf8;
  if (!strcmp(encoding, "iso-8859-3")) return (TUTF8encoder) tutf8e_iso_8859_3_utf8;
  if (!strcmp(encoding, "iso-8859-4")) return (TUTF8encoder) tutf8e_iso_8859_4_utf8;
  if (!strcmp(encoding, "iso-8859-5")) return (TUTF8encoder) tutf8e_iso_8859_5_utf8;
  if (!strcmp(encoding, "iso-8859-6")) return (TUTF8encoder) tutf8e_iso_8859_6_utf8;
  if (!strcmp(encoding, "iso-8859-7")) return (TUTF8encoder) tutf8e_iso_8859_7_utf8;
  if (!strcmp(encoding, "iso-8859-8")) return (TUTF8encoder) tutf8e_iso_8859_8_utf8;
  if (!strcmp(encoding, "iso-8859-9")) return (TUTF8encoder) tutf8e_iso_8859_9_utf8;
  if (!strcmp(encoding, "windows-1250")) return (TUTF8encoder) tutf8e_windows_1250_utf8;
  if (!strcmp(encoding, "windows-1251")) return (TUTF8encoder) tutf8e_windows_1251_utf8;
  if (!strcmp(encoding, "windows-1252")) return (TUTF8encoder) tutf8e_windows_1252_utf8;
  if (!strcmp(encoding, "windows-1253")) return (TUTF8encoder) tutf8e_windows_1253_utf8;
  if (!strcmp(encoding, "windows-1254")) return (TUTF8encoder) tutf8e_windows_1254_utf8;
  if (!strcmp(encoding, "windows-1255")) return (TUTF8encoder) tutf8e_windows_1255_utf8;
  if (!strcmp(encoding, "windows-1256")) return (TUTF8encoder) tutf8e_windows_1256_utf8;
  if (!strcmp(encoding, "windows-1257")) return (TUTF8encoder) tutf8e_windows_1257_utf8;
  if (!strcmp(encoding, "windows-1258")) return (TUTF8encoder) tutf8e_windows_1258_utf8;

  return NULL;
}

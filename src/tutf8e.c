
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

int tutf8e_string_encode(const uint16_t *table, const char *i, char *o, size_t *olen)
{
  int ret;
  size_t ilen = 0;
  size_t length = 0;
  if (!(ret = tutf8e_string_length(table, i, &ilen, &length)))
  {
    if (length+1 > *olen) return TUTF8E_TOOLONG;
    if (ilen && !(ret = tutf8e_buffer_encode(table, i, ilen, o, olen)))
    {
      o[length] = 0;
      return TUTF8E_OK;
    }
  }
  return ret;
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
  if (!strcmp(encoding, "iso-8859-1")) return tutf8e_encoder_iso_8859_1;
  if (!strcmp(encoding, "iso-8859-10")) return tutf8e_encoder_iso_8859_10;
  if (!strcmp(encoding, "iso-8859-11")) return tutf8e_encoder_iso_8859_11;
  if (!strcmp(encoding, "iso-8859-13")) return tutf8e_encoder_iso_8859_13;
  if (!strcmp(encoding, "iso-8859-14")) return tutf8e_encoder_iso_8859_14;
  if (!strcmp(encoding, "iso-8859-15")) return tutf8e_encoder_iso_8859_15;
  if (!strcmp(encoding, "iso-8859-16")) return tutf8e_encoder_iso_8859_16;
  if (!strcmp(encoding, "iso-8859-2")) return tutf8e_encoder_iso_8859_2;
  if (!strcmp(encoding, "iso-8859-3")) return tutf8e_encoder_iso_8859_3;
  if (!strcmp(encoding, "iso-8859-4")) return tutf8e_encoder_iso_8859_4;
  if (!strcmp(encoding, "iso-8859-5")) return tutf8e_encoder_iso_8859_5;
  if (!strcmp(encoding, "iso-8859-6")) return tutf8e_encoder_iso_8859_6;
  if (!strcmp(encoding, "iso-8859-7")) return tutf8e_encoder_iso_8859_7;
  if (!strcmp(encoding, "iso-8859-8")) return tutf8e_encoder_iso_8859_8;
  if (!strcmp(encoding, "iso-8859-9")) return tutf8e_encoder_iso_8859_9;
  if (!strcmp(encoding, "windows-1250")) return tutf8e_encoder_windows_1250;
  if (!strcmp(encoding, "windows-1251")) return tutf8e_encoder_windows_1251;
  if (!strcmp(encoding, "windows-1252")) return tutf8e_encoder_windows_1252;
  if (!strcmp(encoding, "windows-1253")) return tutf8e_encoder_windows_1253;
  if (!strcmp(encoding, "windows-1254")) return tutf8e_encoder_windows_1254;
  if (!strcmp(encoding, "windows-1255")) return tutf8e_encoder_windows_1255;
  if (!strcmp(encoding, "windows-1256")) return tutf8e_encoder_windows_1256;
  if (!strcmp(encoding, "windows-1257")) return tutf8e_encoder_windows_1257;
  if (!strcmp(encoding, "windows-1258")) return tutf8e_encoder_windows_1258;

  return NULL;
}

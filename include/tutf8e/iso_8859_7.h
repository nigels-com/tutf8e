
#ifndef TUTF8E_ISO_8859_7_H
#define TUTF8E_ISO_8859_7_H

#include <tutf8e.h>

static inline int tutf8e_iso_8859_7_string_length(const char *i, size_t *ilen, size_t *olen)
{
  return tutf8e_encoder_string_length(tutf8e_encoder_iso_8859_7, i, ilen, olen);
}

static inline int tutf8e_iso_8859_7_string_encode(const char *i, char *o, size_t *olen)
{
  return tutf8e_encoder_string_encode(tutf8e_encoder_iso_8859_7, i, o, olen);
}

static inline int tutf8e_iso_8859_7_buffer_length(const char *i, size_t ilen, size_t *length)
{
  return tutf8e_encoder_buffer_length(tutf8e_encoder_iso_8859_7, i, ilen, length);
}

static inline int tutf8e_iso_8859_7_buffer_encode(const char *i, size_t ilen, char *o, size_t *olen)
{
  return tutf8e_encoder_buffer_encode(tutf8e_encoder_iso_8859_7, i, ilen, o, olen);
}

#endif

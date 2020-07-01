
#ifndef TUTF8E_ISO_8859_9_H
#define TUTF8E_ISO_8859_9_H

#include <tutf8e.h>

static inline int tutf8e_iso_8859_9_string_length(const char *input, size_t *input_length, size_t *output_length)
{
  return tutf8e_encoder_string_length(tutf8e_encoder_iso_8859_9, input, input_length, output_length);
}

static inline int tutf8e_iso_8859_9_string_encode(const char *input, char *output, size_t *output_length)
{
  return tutf8e_encoder_string_encode(tutf8e_encoder_iso_8859_9, input, output, output_length);
}

static inline int tutf8e_iso_8859_9_buffer_length(const char *i, size_t input_length, size_t *length)
{
  return tutf8e_encoder_buffer_length(tutf8e_encoder_iso_8859_9, input, input_length, length);
}

static inline int tutf8e_iso_8859_9_buffer_encode(const char *i, size_t input_length, char *output, size_t *output_length)
{
  return tutf8e_encoder_buffer_encode(tutf8e_encoder_iso_8859_9, input, input_length, output, output_length);
}

#endif

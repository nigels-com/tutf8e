
#ifndef TUTF8E_WINDOWS_1258_H
#define TUTF8E_WINDOWS_1258_H

#include <tutf8e.h>

static inline int tutf8e_windows_1258_string_length(const char *input, size_t *input_length, size_t *output_length)
{
  return tutf8e_encoder_string_length(tutf8e_encoder_windows_1258, input, input_length, output_length);
}

static inline int tutf8e_windows_1258_string_encode(const char *input, char *output, size_t *output_length)
{
  return tutf8e_encoder_string_encode(tutf8e_encoder_windows_1258, input, output, output_length);
}

static inline int tutf8e_windows_1258_buffer_length(const char *i, size_t input_length, size_t *length)
{
  return tutf8e_encoder_buffer_length(tutf8e_encoder_windows_1258, input, input_length, length);
}

static inline int tutf8e_windows_1258_buffer_encode(const char *i, size_t input_length, char *output, size_t *output_length)
{
  return tutf8e_encoder_buffer_encode(tutf8e_encoder_windows_1258, input, input_length, output, output_length);
}

#endif

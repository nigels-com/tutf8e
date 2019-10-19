
#ifndef TUTF8E_H
#define TUTF8E_H

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

/* Internal API */
extern int tutf8e_string_length(const uint16_t *table, const char *i, size_t *ilen, size_t *olen);
extern int tutf8e_buffer_length(const uint16_t *table, const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_encode(const uint16_t *table, const char *i, size_t ilen, char *output, size_t olen);

/* External API */

/* Encode NUL-terminated string to UTF8 */
extern int tutf8e_string_encode_iso_8859_1  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_10 (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_11 (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_13 (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_14 (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_15 (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_16 (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_2  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_3  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_4  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_5  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_6  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_7  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_8  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_iso_8859_9  (char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1250(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1251(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1252(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1253(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1254(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1255(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1256(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1257(char *output, size_t olen, const char *input);
extern int tutf8e_string_encode_windows_1258(char *output, size_t olen, const char *input);

/* Encode NUL-terminated string to UTF8, realloc as necessary */
extern char * tutf8e_string_encode_iso_8859_1_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_10_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_11_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_13_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_14_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_15_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_16_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_2_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_3_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_4_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_5_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_6_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_7_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_8_realloc(char *input);
extern char * tutf8e_string_encode_iso_8859_9_realloc(char *input);
extern char * tutf8e_string_encode_windows_1250_realloc(char *input);
extern char * tutf8e_string_encode_windows_1251_realloc(char *input);
extern char * tutf8e_string_encode_windows_1252_realloc(char *input);
extern char * tutf8e_string_encode_windows_1253_realloc(char *input);
extern char * tutf8e_string_encode_windows_1254_realloc(char *input);
extern char * tutf8e_string_encode_windows_1255_realloc(char *input);
extern char * tutf8e_string_encode_windows_1256_realloc(char *input);
extern char * tutf8e_string_encode_windows_1257_realloc(char *input);
extern char * tutf8e_string_encode_windows_1258_realloc(char *input);

/* Encode buffer to UTF8 */
extern int tutf8e_buffer_encode_iso_8859_1  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_10 (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_11 (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_13 (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_14 (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_15 (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_16 (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_2  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_3  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_4  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_5  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_6  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_7  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_8  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_9  (char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1250(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1251(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1252(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1253(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1254(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1255(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1256(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1257(char *output, size_t olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1258(char *output, size_t olen, const char *input, size_t ilen);

#endif

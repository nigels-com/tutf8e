
#ifndef TUTF8E_H
#define TUTF8E_H

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

/* Internal API */
extern int tutf8e_string_length(const uint16_t *table, const char *i, size_t *ilen, size_t *olen);
extern int tutf8e_buffer_length(const uint16_t *table, const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_encode(const uint16_t *table, const char *i, size_t ilen, char *output, size_t *olen);

/* External API */

#define TUTF8E_OK      0 /* Success                    */
#define TUTF8E_INVALID 1 /* Invalid input character    */
#define TUTF8E_TOOLONG 2 /* Insufficient output buffer */

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

/* Buffer length as UTF8 */
extern int tutf8e_buffer_length_iso_8859_1  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_10 (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_11 (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_13 (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_14 (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_15 (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_16 (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_2  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_3  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_4  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_5  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_6  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_7  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_8  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_iso_8859_9  (const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1250(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1251(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1252(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1253(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1254(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1255(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1256(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1257(const char *i, size_t ilen, size_t *length);
extern int tutf8e_buffer_length_windows_1258(const char *i, size_t ilen, size_t *length);

/* Encode buffer to UTF8 */
extern int tutf8e_buffer_encode_iso_8859_1  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_10 (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_11 (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_13 (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_14 (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_15 (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_16 (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_2  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_3  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_4  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_5  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_6  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_7  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_8  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_iso_8859_9  (char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1250(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1251(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1252(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1253(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1254(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1255(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1256(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1257(char *output, size_t *olen, const char *input, size_t ilen);
extern int tutf8e_buffer_encode_windows_1258(char *output, size_t *olen, const char *input, size_t ilen);

#endif

#ifndef TUTF8E_H
#define TUTF8E_H

#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

extern int encode_iso_8859_1_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_10_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_11_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_13_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_14_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_15_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_16_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_2_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_3_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_4_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_5_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_6_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_7_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_8_utf8(char *dest, size_t size, const char *src);
extern int encode_iso_8859_9_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1250_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1251_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1252_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1253_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1254_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1255_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1256_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1257_utf8(char *dest, size_t size, const char *src);
extern int encode_windows_1258_utf8(char *dest, size_t size, const char *src);

#endif

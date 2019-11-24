/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Input/Output header
*/

#ifndef FOX_IO_H
#define FOX_IO_H

#include <sys/types.h>
#include "fox_define.h"

// Print a single character to a given file descriptor
scount_t fox_dputchar(int fd, char c);
#define fox_putchar(c)  fox_dputchar(1, (c)) // -> STDOUT
#define fox_eputchar(c) fox_dputchar(2, (c)) // -> STDERR

// Print a character in octal (\xxx) to given fd
scount_t fox_dputchar_oct(int fd, uchar_t c);
#define fox_putchar_oct(c)  fox_dputchar_oct(1, (c)) // -> STDOUT
#define fox_eputchar_oct(c) fox_dputchar_oct(2, (c)) // -> STDERR

// Print n times the character pad to given fd
scount_t fox_diopadn(int fd, uchar_t pad, count_t n);
#define fox_iopadn(c, n)  fox_diopadn(1, (c), (n)) // -> STDOUT
#define fox_eiopadn(c, n) fox_diopadn(2, (c), (n)) // -> STDERR

// Print a string to a given file descriptor
scount_t fox_dputstr(int fd, str2c_t str);
#define fox_putstr(str)  fox_dputstr(1, (str)) // -> STDOUT
#define fox_eputstr(str) fox_dputstr(2, (str)) // -> STDERR

// Print a string, including non printables as '\xxx' to a given fd
scount_t fox_dputstr_np(int fd, str2c_t str);
#define fox_putstr_np(str)  fox_dputstr_np(1, (str)) // -> STDOUT
#define fox_eputstr_np(str) fox_dputstr_np(2, (str)) // -> STDERR

// Print a number to a given file descriptor
scount_t fox_dputnbr(int fd, llong_t n);
#define fox_putnbr(n)  fox_dputnbr(1, (n)) // -> STDOUT
#define fox_eputnbr(n) fox_dputnbr(2, (n)) // -> STDERR

// Print an unsigned number to a given file descriptor
scount_t fox_dputunbr(int fd, ullong_t n);
#define fox_putunbr(n)  fox_dputunbr(1, (n)) // -> STDOUT
#define fox_eputunbr(n) fox_dputunbr(2, (n)) // -> STDERR

// Print an unsigned number in given base to given fd
scount_t fox_dputunbr_base(int fd, ullong_t n, str2c_t base) __nonnull;
#define fox_putunbr_base(n, b)  fox_dputunbr_base(1, (n), (b)) // -> STDOUT
#define fox_eputunbr_base(n, b) fox_dputunbr_base(2, (n), (b)) // -> STDERR

// Write c into already allocated s
// Returns number of bytes written (always 4)
count_t fox_sputchar(str_t s, uchar_t c) __nonnull __const;

// Write c in octal (\xxx) into already allocated s
// Returns number of bytes written (always 4)
count_t fox_sputchar_oct(str_t s, uchar_t c) __nonnull __const;

// Write pad n times in buffer s
// Returns number of written character
count_t fox_siopadn(str_t s, uchar_t pad, scount_t n) __nonnull __const;

// Write str into already allocated s
// Returns number of bytes written
count_t fox_sputstr(str_t s, str2c_t str) __nonnull;

// Write str into already allocated s (including non-printables)
// Returns number of bytes written
count_t fox_sputstr_np(str_t s, str2c_t str) __nonnull;

// Write an integer to an already allocated string
// Returns number of bytes written
count_t fox_sputnbr(str_t s, llong_t n) __nonnull;

// Write an unsigned integer to an already allocated string
// Returns number of bytes written
count_t fox_sputunbr(str_t s, llong_t n) __nonnull;

// Write an unsigned integer in given base into an already allocated string
// Returns number of bytes written or -1 if fox_verifbase(base) != false
scount_t fox_sputunbr_base(str_t s, ullong_t n, str2c_t base) __nonnull;

// Allocate s and print c into it
// Returns -1 in case of failed allocation
scount_t fox_asputchar(str_t *s, char c) __nonnull;

// Allocate s and print c in octal (\xxx) into it
// Returns -1 in case of failed allocation
scount_t fox_asputchar_oct(str_t *s, uchar_t c) __nonnull;

// Allocate s and print str into it
// Returns -1 in case of failed allocation
scount_t fox_asputstr(str_t *s, str2c_t str) __a((nonnull(1)));

// Allocate s and print str (including non-printables) into it
// Returns -1 in case of failed allocation
scount_t fox_asputstr_np(str_t *s, str2c_t str) __a((nonnull(1)));

// Allocate s and print n (signed) into it
// Returns -1 in case of failed allocation
scount_t fox_asputnbr(str_t *s, llong_t n) __nonnull;

// Allocate s and print n (unsigned) into it
// Returns -1 in case of failed allocation
scount_t fox_asputunbr(str_t *s, ullong_t n) __nonnull;

// Allocate s and print n in given base into it
// Returns -1 in case of failed allocation
scount_t fox_asputunbr_base(str_t *s, ullong_t n, str2c_t base) __nonnull;

#endif /* !FOX_IO_H */

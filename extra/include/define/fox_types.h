/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Various typedefs
*/

#ifndef FOX_TYPES_H
#define FOX_TYPES_H

#include <stddef.h>

#ifndef FOX_UCHAR_TYPE
    #define FOX_UCHAR_TYPE
    typedef unsigned char byte_t;
    typedef unsigned char uchar_t;
#endif // FOX_UCHAR_TYPE

#ifndef FOX_STR_TYPE
    #define FOX_STR_TYPE
    typedef char *                      str_t;
    typedef char const *                str2c_t;
    typedef char const * const          str3c_t;
    typedef char const * const * const  str4c_t;
#endif // FOX_STR_TYPE

#ifndef FOX_WSTR_TYPE
    #define FOX_WwSTR_TYPE
    typedef wchar_t *                      wstr_t;
    typedef wchar_t const *                wstr2c_t;
    typedef wchar_t const * const          wstr3c_t;
    typedef wchar_t const * const * const  wstr4c_t;
#endif // FOX_WSTR_TYPE

#ifndef FOX_USHORT_TYPE
    #define FOX_USHORT_TYPE
    typedef unsigned short hbmask_t;
    typedef unsigned short hcount_t;
    typedef unsigned short hindex_t;
    typedef unsigned short hsize_t;
    typedef unsigned short ushort_t;
#endif // FOX_USHORT_TYPE

#ifndef FOX_UINT_TYPE
    #define FOX_UINT_TYPE
    typedef unsigned int ibmask_t;
#endif // FOX_INT_TYPE

#ifndef FOX_LONG_TYPE
    #define FOX_LONG_TYPE
    typedef long scount_t;
#endif // FOX_LONG_TYPE

#ifndef FOX_ULONG_TYPE
    #define FOX_ULONG_TYPE
    typedef unsigned long ulong_t;
    typedef unsigned long count_t;
    typedef unsigned long index_t;
    typedef unsigned long bmask_t;
#endif

#ifndef FOX_LLONG_TYPE
    #define FOX_LLONG_TYPE
    typedef long long llong_t;
    typedef long long lcount_t;
#endif // FOX_LLONG_TYPE

#ifndef FOX_ULLONG_TYPE
    #define FOX_ULLONG_TYPE
    typedef unsigned long long ullong_t;
#endif // FOX_ULLONG_TYPE

#ifndef FOX_LDOUBLE_TYPE
    #define FOX_LDOUBLE_TYPE
    typedef long double ldouble_t;
#endif // FOX_LDOUBLE_TYPE

#endif /* !FOX_TYPES_H */

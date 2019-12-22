/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Include every wrapper
*/

#ifndef FOX_WRAPPERS_H
#define FOX_WRAPPERS_H

/* FCNTL / UNISTD */
#include "wrapdef/fox_wrap_close.h"
#include "wrapdef/fox_wrap_open.h"
#include "wrapdef/fox_wrap_read.h"
#include "wrapdef/fox_wrap_write.h"

/* MALLOC */
#include "wrapdef/fox_wrap_malloc.h"

/* NCURSES */
#include "wrapdef/fox_wrap_cbreak.h"
#include "wrapdef/fox_wrap_initscr.h"
#include "wrapdef/fox_wrap_keypad.h"
#include "wrapdef/fox_wrap_noecho.h"

#endif /* !FOX_WRAPPERS_H */

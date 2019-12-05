/*
** EPITECH PROJECT, 2019
** Libfox
** File description:
** Include every wrapper
*/

#ifndef FOX_WRAPPERS_H
#define FOX_WRAPPERS_H

/* FCNTL / UNISTD */
#include "wrappers/wrap_close.h"
#include "wrappers/wrap_open.h"
#include "wrappers/wrap_read.h"
#include "wrappers/wrap_write.h"

/* MALLOC */
#include "wrappers/wrap_malloc.h"

/* NCURSES */
#include "wrappers/wrap_cbreak.h"
#include "wrappers/wrap_initscr.h"
#include "wrappers/wrap_keypad.h"
#include "wrappers/wrap_noecho.h"

#endif /* !FOX_WRAPPERS_H */

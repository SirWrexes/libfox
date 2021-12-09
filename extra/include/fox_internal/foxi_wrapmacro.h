/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** Macro for generating a standard function wrapper
*/

#ifndef FOXI_WRAPMACRO_H
#define FOXI_WRAPMACRO_H

#define Wrapper(Ret, Func, Args...) \
    Ret __real_##Func(Args);        \
    Ret __wrap_##Func(Args)

#endif /* !FOXI_WRAPMACRO_H */

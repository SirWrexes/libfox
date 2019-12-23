/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** fox_csfml.h -- No description
*/

#ifndef FOX_CSFML_H
#define FOX_CSFML_H

/*
** This module tries to reproduce an object oriented environment for CSFML
** projects as well as give the users a handy toolbox for this same lib.
**
** You're probably wondering why not just use an OOP binding of SFML, or
** even just SFML instead... Well, the answer to that question is on line 2
** of every single source and header that composes this lib.
**
** Anyway don't hesitate and dig in the headers, they're well commentend.
** ... At least for the ones that you need to understand to use the module.
**
** I hope this makes your experiences with CSFML better !
*/

// This is the object structures
#include "types/foxcsfml_types.h"

// This is the part that generates your objects and constructors
// Macros preceeded with the "STATIC" comment generate static const variables.
// To avoid clogging your memory, use them only in headers that you include in
// the source containing your object's constructor.
#include "internal/foxcsfml_internal.h"

#endif /* !FOX_CSFML_H */

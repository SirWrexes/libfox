/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** private.h -- No description
*/

#ifndef PRIVATE_H
#define PRIVATE_H

// Definition types
#define __StaConst(type)   static const type
#define __ExtConst_d(type) extern const type // _d stands for declare
#define __ExtConst_s(type) const type        // _s stands for set

// Maxframes deduction based on rectangle count
#define __aiData_maxframes(sprite, anim)       \
    (sizeof(__aiData_key(sprite, anim, RECTS)) \
        / sizeof(__aiData_key(sprite, anim, RECTS)[0]))

// Metadata variable name resolution based on sprite and anim names
#define __aiData_key(sprite, anim, key) AIDATA_##sprite##_##anim##_##key
#define __aiData_meta_list(sprite)      AIDATA_META_LIST_##sprite
#define __siData_key(sprite, key)       SIDATA_##sprite##_##key

#endif /* !PRIVATE_H */

#ifndef RNG_H
#define RNG_H

#include <basics/types.h>

#include "var.h"

extern void random_set_seed(u64 newSeed);
extern u32 random(void);
extern s32 random_range(s32 min, s32 max);

#endif
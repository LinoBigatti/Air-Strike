#include "rng.h"

u64 seed = 1257352426586363;

void random_set_seed(u64 newSeed) {
	seed = newSeed;
}

u32 random(void) {
	seed = 1664525 * seed + 1013904223;
    return (seed >> 16) & 0x7FFF;
}

s32 random_range(s32 min, s32 max) {
	u32 result = random();
	result = (result * (max - min) >> 15) + min;
	return result;
}

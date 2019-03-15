#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <basics/types.h>
#include <IO.h>
#include <background/bg_defs.h>
#include <object/obj_defs.h>
#include <DMA.h>

#include "time.h"
#include "var.h"

#include "bg-tiles.h"
#include "BG0_1.h"
#include "BG0_2.h"
#include "BG1.h"
#include "player.h"
#include "island.h"
#include "radar.h"

extern void update_gfx(void);
extern void load_gfx(void);
extern void load_gfx_IO(void);

static inline void setup_gfx(void) {
	load_gfx();
	load_gfx_IO();
}

#endif
//Time functions.

#ifndef TIME_H
#define TIME_H

#include <basics/types.h>
#include <basics/vsync.h>

#include "var.h"

extern void update_timer(void);
extern void reset_timer(void);
extern void hard_reset_timer(void);
extern void delay(u32 seconds);

#endif
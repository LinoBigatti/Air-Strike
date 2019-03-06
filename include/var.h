#ifndef VAR_H
#define VAR_H

#include <basics/types.h>
#include <object/obj_defs.h>
#include <object/obj_attribute_1.h>

//Object pointers
extern obj_attributes *g_player;

//Time registers
extern u64 g_absoluteFrames;
extern u64 g_relativeFrames;
extern u32 g_seconds;
extern u32 g_minutes;
extern u32 g_hours;

//Player variables
extern u32 g_playerX;
extern u32 g_playerY;
extern u32 g_playerFlipH;
extern u32 g_playerFlipV;
extern u32 g_playerAnimState;

#endif
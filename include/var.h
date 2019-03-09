#ifndef VAR_H
#define VAR_H

#include <basics/types.h>
#include <object/obj_defs.h>
#include <object/obj_attribute_0.h>
#include <object/obj_attribute_1.h>

//Object pointers
extern obj_attributes *g_player;
extern obj_attributes *g_island;
extern obj_attributes *g_radar;
extern obj_attributes *g_radarWin;

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
extern u32 g_playerState;
extern u32 g_playerRadarX;
extern u32 g_playerRadarY;
extern u32 g_playerVisibility;

//Island variables
extern u32 g_islandXS_p;
extern u32 g_islandYS_p;
extern u32 g_islandXE_p;
extern u32 g_islandYE_p;
extern u32 g_islandXS_r;
extern u32 g_islandYS_r;
extern u32 g_islandXE_r;
extern u32 g_islandYE_r;
extern u32 g_islandVisibility;

//Bg variables
extern u32 g_screenX;
extern u32 g_screenY;
extern u32 g_radarScreenX;
extern u32 g_radarScreenY;

#endif
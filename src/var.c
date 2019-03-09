#include "var.h"

//Object pointers
obj_attributes *g_player = &obj_reg_memory[0];
obj_attributes *g_island = &obj_reg_memory[1];
obj_attributes *g_radar = &obj_reg_memory[2];
obj_attributes *g_radarWin = &obj_reg_memory[3];

//Time registers
u64 g_absoluteFrames = 0;
u64 g_relativeFrames = 0;
u32 g_seconds = 0;
u32 g_minutes = 0;
u32 g_hours = 0;

//Player variables
u32 g_playerX = 0;
u32 g_playerY = 0;
u32 g_playerFlipH = 0;
u32 g_playerFlipV = attr1_vflip;
u32 g_playerAnimState = 0;
u32 g_playerState = 0;
u32 g_playerRadarX = 0;
u32 g_playerRadarY = 0;
u32 g_playerVisibility = 0;

//Island variables
u32 g_islandXS_p = 0;
u32 g_islandYS_p = 0;
u32 g_islandXE_p = 0;
u32 g_islandYE_p = 0;
u32 g_islandXS_r = 0;
u32 g_islandYS_r = 0;
u32 g_islandXE_r = 0;
u32 g_islandYE_r = 0;
u32 g_islandVisibility = attr0_hide;

//Bg variables
u32 g_screenX = 0;
u32 g_screenY = 0;
u32 g_radarScreenX = 0;
u32 g_radarScreenY = 0;
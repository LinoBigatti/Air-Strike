#include "var.h"

//Object pointers
obj_attributes *g_player = &obj_reg_memory[0];
obj_attributes *g_island = &obj_reg_memory[1];

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

//Island variables
u32 g_islandXS = 0;
u32 g_islandYS = 0;
u32 g_islandXE = 0;
u32 g_islandYE = 0;

//Bg variables
u32 g_screenX = 0;
u32 g_screenY = 0;
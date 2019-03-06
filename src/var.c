#include "var.h"

//Object pointers
obj_attributes *g_player = &obj_reg_memory[0];

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
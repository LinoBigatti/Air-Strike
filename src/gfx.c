#include "gfx.h"

u32 past_seconds = 0, mapFrame = 1, spriteFrame = 1;

void update_gfx(void) {
	//Animate
	if(g_seconds != past_seconds) {
		past_seconds = g_seconds;
		if(mapFrame == 1) {
			mapFrame = 2;
			dma3_32(bg0_2, (u32*)&se_memory[30][0], bg0_2Len / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
		} else {
			mapFrame = 1;
			dma3_32(bg0_1, (u32*)&se_memory[30][0], bg0_1Len / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
		}
	}
	
	if((g_relativeFrames == 29) || (g_relativeFrames == 59)) {
		if(spriteFrame == 1) {
			spriteFrame = 2;
			g_player->attr2 = attr2_build(attr2_base_tile(g_playerAnimState), attr2_priority(0), attr2_palbank(0));
		} else {
			spriteFrame = 1;
			g_player->attr2 = attr2_build(attr2_base_tile(g_playerAnimState + 4), attr2_priority(0), attr2_palbank(0));
		}
	}
	
	//Move
	g_player->attr0 = attr0_build(attr0_Y(g_playerY), g_playerVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_player->attr1 = attr1_regular_build(attr1_X(g_playerX), g_playerFlipH, g_playerFlipV, attr1_size(OBJ_16x16));
	g_radar->attr0 = attr0_build(attr0_Y(g_playerRadarY), g_islandVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_radarWin->attr0 = attr0_build(attr0_Y(g_playerRadarY), g_islandVisibility, attr0_window, 0, attr0_4bpp, attr0_square);
	g_radar->attr1	= attr1_regular_build(attr1_X(g_playerRadarX), 0, 0, attr1_size(OBJ_32x32));
	g_radarWin->attr1 = attr1_regular_build(attr1_X(g_playerRadarX), 0, 0, attr1_size(OBJ_32x32));
	
	if(g_playerState == 0) {
		g_island->attr0 = attr0_build(attr0_Y(g_islandYS_p), g_islandVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
		g_island->attr1 = attr1_regular_build(attr1_X(g_islandXS_p), 0, 0, attr1_size(OBJ_32x32));
		IO_BG0HOFS = IO_BG1HOFS = g_screenX;
		IO_BG0VOFS = IO_BG1VOFS = g_screenY;
	} else {
		g_island->attr0 = attr0_build(attr0_Y(g_islandYS_r), g_islandVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
		g_island->attr1 = attr1_regular_build(attr1_X(g_islandXS_r), 0, 0, attr1_size(OBJ_32x32));
		IO_BG0HOFS = IO_BG1HOFS = g_radarScreenX;
		IO_BG0VOFS = IO_BG1VOFS = g_radarScreenY;
	}
}

void load_gfx(void) {
	obj_clear_all();
	
	dma3_32(bgPal1, bg_pal_memory, bgPal1Len / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(bgTiles, (u32*)&tile8_vram[0][0], bgTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(bg0_1, (u32*)&se_memory[30][0], bg0_1Len / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(bg1, (u32*)&se_memory[31][0], bg1Len / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	
	dma3_32(playerPal, (u32*)&obj_pal_memory[0], playerPalLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(playerTiles, (u32*)&tile_vram[4][0], playerTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	
	dma3_32(islandPal, (u32*)&obj_pal_memory[16], islandPalLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(islandTiles, (u32*)&tile_vram[4][16], islandTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	
	dma3_32(radarPal, (u32*)&obj_pal_memory[32], radarPalLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(radarTiles, (u32*)&tile_vram[4][48], radarTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	dma3_32(radar_windowTiles, (u32*)&tile_vram[4][80], radar_windowTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
}

void load_gfx_IO(void) {
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_prio(2) | bg0cnt_sbb(30) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
	IO_BG1CNT = bg1cnt_cbb(0) | bg1cnt_prio(0) | bg1cnt_sbb(31) | bg1cnt_8bpp | bg1cnt_size(BG_32x32);
	
	g_player->attr0 = attr0_build(attr0_Y(g_playerY), g_playerVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_player->attr1 = attr1_regular_build(attr1_X(g_playerX), g_playerFlipH, g_playerFlipV, attr1_size(OBJ_16x16));
	g_player->attr2 = attr2_build(attr2_base_tile(g_playerAnimState), attr2_priority(0), attr2_palbank(0));
	
	g_island->attr0 = attr0_build(attr0_Y(g_islandYS_p), g_islandVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_island->attr1 = attr1_regular_build(attr1_X(g_islandXS_p), 0, 0, attr1_size(OBJ_32x32));
	g_island->attr2 = attr2_build(attr2_base_tile(16), attr2_priority(1), attr2_palbank(1));
	
	g_radar->attr0 = attr0_build(attr0_Y(g_playerRadarY), g_islandVisibility, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_radar->attr1 = attr1_regular_build(attr1_X(g_playerRadarX), 0, 0, attr1_size(OBJ_32x32));
	g_radar->attr2 = attr2_build(attr2_base_tile(48), attr2_priority(0), attr2_palbank(2));
	
	g_radarWin->attr0 = attr0_build(attr0_Y(g_playerRadarY), g_islandVisibility, attr0_window, 0, attr0_4bpp, attr0_square);
	g_radarWin->attr1 = attr1_regular_build(attr1_X(g_playerRadarX), 0, 0, attr1_size(OBJ_32x32));
	g_radarWin->attr2 = attr2_build(attr2_base_tile(80), attr2_priority(0), attr2_palbank(2));
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0 | dispcnt_BG1 | dispcnt_OBJ | dispcnt_obj_mapping_1D | dispcnt_WINOBJ;
	IO_WINOUT = winout_winout(0, winout_winoutBG1, 0, 0, winout_winoutOBJ, 0) | winout_winobj(winout_winobjBG0, 0, 0, 0, winout_winobjOBJ, 0);
}
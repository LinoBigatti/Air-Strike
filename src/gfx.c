#include "gfx.h"

u32 past_seconds = 0, mapFrame = 1, spriteFrame = 1;

void update_gfx(void) {
	//Animate
	if(g_seconds != past_seconds) {
		past_seconds = g_seconds;
		if(mapFrame == 1) {
			mapFrame = 2;
			bg_map_32(bg0_2, bg0_2Len / 4, 30);
		} else {
			mapFrame = 1;
			bg_map_32(bg0_1, bg0_1Len / 4, 30);
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
	g_player->attr0 = attr0_build(attr0_Y(g_playerY), attr0_regular, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_player->attr1 = attr1_regular_build(attr1_X(g_playerX), g_playerFlipH, g_playerFlipV, attr1_size(OBJ_16x16));
}

void load_gfx(void) {
	obj_clear_all();
	
	bg_palette_32(bgPal, bgPalLen / 4, 0);
	bg_tileset_32(bgTiles, bgTilesLen / 4, 0, 8);
	bg_map_32(bg0_1, bg0_1Len / 4, 30);
	bg_map_32(bg1, bg1Len / 4, 31);
	
	obj_palette_32(playerPal, playerPalLen / 4, 0);
	obj_tiles_32(playerTiles, playerTilesLen / 4, 4, 0, 4);
}

void load_gfx_IO(void) {
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_prio(2) | bg0cnt_sbb(30) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
	IO_BG1CNT = bg1cnt_cbb(0) | bg1cnt_prio(0) | bg1cnt_sbb(31) | bg1cnt_8bpp | bg1cnt_size(BG_32x32);
	
	g_player->attr0 = attr0_build(attr0_Y(g_playerY), attr0_regular, attr0_normal, 0, attr0_4bpp, attr0_square);
	g_player->attr1 = attr1_regular_build(attr1_X(g_playerX), g_playerFlipH, g_playerFlipV, attr1_size(OBJ_16x16));
	g_player->attr2 = attr2_build(attr2_base_tile(g_playerAnimState), attr2_priority(0), attr2_palbank(0));
	
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0 | dispcnt_BG1 | dispcnt_OBJ | dispcnt_obj_mapping_1D;
}
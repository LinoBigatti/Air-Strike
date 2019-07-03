#include "winScreen.h"

int x = 1;

void winScreen(void) {
	IO_DISPCNT = 0;
	
	g_playerX = 0;
	g_playerY = 0;
	g_playerFlipH = 0;
	g_playerFlipV = attr1_vflip;
	g_playerAnimState = 0;
	g_playerState = 0;
	g_playerRadarX = 0;
	g_playerRadarY = 0;
	g_playerVisibility = 0;
	
	g_islandXS_p = 0;
	g_islandYS_p = 0;
	g_islandXE_p = 0;
	g_islandYE_p = 0;
	g_islandVisibility = attr0_hide;
	
	g_screenX = 0;
	g_screenY = 0;
	
	g_islandXE_p = (g_islandXS_p = random_range(0, 208)) + 32;
	g_islandYE_p = (g_islandYS_p = random_range(0, 118)) + 32;
	
	IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_prio(0) | bg0cnt_sbb(31) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
	if(read_8(0) == 'e') {
		dma3_32(win_screenPal, bg_pal_memory, win_screenPalLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
		dma3_32(win_screenTiles, (u32*)&tile8_vram[0][0], win_screenTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
		dma3_32(win_screenMap, (u32*)&se_memory[31][0], win_screenMapLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	} else if(read_8(0) == 's') {
		dma3_32(win_screen_esPal, bg_pal_memory, win_screen_esPalLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
		dma3_32(win_screen_esTiles, (u32*)&tile8_vram[0][0], win_screen_esTilesLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
		dma3_32(win_screen_esMap, (u32*)&se_memory[31][0], win_screen_esMapLen / 4, dmacnt_incdst, dmacnt_incsrc, dmacnt_inmediate, 0);
	}
	IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0;
	IO_BG0HOFS = IO_BG0VOFS = 0;
	
	while(x) {
		key_update();
		update_timer();
		if(key_start_pressing(BUTTON_A)) {
			x = 0;
		}
	}
	
	x = 1;
	setup_gfx();
}
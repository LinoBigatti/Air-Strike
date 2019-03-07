#include "control.h"

void handle_input(void) {
	key_update();
	
	if(key_is_pressed(BUTTON_RIGHT)) {
		if(g_playerX != 224) {
			g_playerX += 1;
			if(g_playerX == 120 && g_screenX != (256 - 240)) {
				g_playerX -= 1;
				g_screenX += 1;
				g_islandXS -= 1;
				g_islandXE -= 1;
			}
		}
		g_playerAnimState = 8;
		g_playerFlipH = 0;
		g_playerFlipV = 0;
	} else if(key_is_pressed(BUTTON_LEFT)) {
		if(g_playerX != 0) {
			g_playerX -= 1;
			if(g_playerX == 112 && g_screenX != 0) {
				g_playerX += 1;
				g_screenX -= 1;
				g_islandXS += 1;
				g_islandXE += 1;
			}
		}
		g_playerAnimState = 8;
		g_playerFlipH = attr1_hflip;
		g_playerFlipV = 0;
	} else if(key_is_pressed(BUTTON_UP)) {
		if(g_playerY != 0) {
			g_playerY -= 1;
			if(g_playerY == 62 && g_screenY != 0) {
				g_playerY += 1;
				g_screenY -= 1;
				g_islandYS += 1;
				g_islandYE += 1;
			}
		}
		g_playerAnimState = 0;
		g_playerFlipH = 0;
		g_playerFlipV = 0;
	} else if(key_is_pressed(BUTTON_DOWN)) {
		if(g_playerY != 144) {
			g_playerY += 1;
			if(g_playerY == 80 && g_screenY != (256 - 160)) {
				g_playerY -= 1;
				g_screenY += 1;
				g_islandYS -= 1;
				g_islandYE -= 1;
			}
		}
		g_playerAnimState = 0;
		g_playerFlipH = 0;
		g_playerFlipV = attr1_vflip;
	}
	if(key_start_pressing(BUTTON_A)) {
		if((g_playerX >= g_islandXS && g_playerX <= g_islandXE) && (g_playerY >= g_islandYS && g_playerY <= g_islandYE)) {
			g_island->attr0 = attr0_build(attr0_Y(g_islandYS), attr0_hide, attr0_normal, 0, attr0_4bpp, attr0_square);
			IO_DISPCNT = 0;
			while(1);
		}
	}
}
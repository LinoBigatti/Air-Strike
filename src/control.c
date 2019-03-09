#include "control.h"

void handle_input(void) {
	key_update();
	
	if(key_start_pressing(BUTTON_START)) {
		g_playerState ^= 1;
		g_playerVisibility ^= attr0_hide;
		g_islandVisibility ^= attr0_hide;
		g_radar->attr0 ^= attr0_hide;
		g_radarWin->attr0 ^= attr0_hide;
		if(g_playerState == 0) {
			bg_palette_32(bgPal1, bgPal1Len / 4, 0);
		} else {
			bg_palette_32(bgPal2, bgPal2Len / 4, 0);
		}
	}
	if(key_is_pressed(BUTTON_RIGHT)) {
		if((g_playerX != 224) && g_playerState == 0) {
			g_playerX += 1;
			if(g_playerX == 120 && g_screenX != (256 - 240)) {
				g_playerX -= 1;
				g_screenX += 1;
				g_islandXS_p -= 1;
				g_islandXE_p -= 1;
			}
		}
		if((g_playerRadarX != 224) && g_playerState == 1) {
			g_playerRadarX += 1;
			if(g_playerRadarX == 120 && g_radarScreenX != (256 - 240)) {
				g_playerRadarX -= 1;
				g_radarScreenX += 1;
				g_islandXS_r -= 1;
				g_islandXE_r -= 1;
			}
		}
		g_playerAnimState = 8;
		g_playerFlipH = 0;
		g_playerFlipV = 0;
	} else if(key_is_pressed(BUTTON_LEFT)) {
		if((g_playerX != 0) && g_playerState == 0) {
			g_playerX -= 1;
			if(g_playerX == 112 && g_screenX != 0) {
				g_playerX += 1;
				g_screenX -= 1;
				g_islandXS_p += 1;
				g_islandXE_p += 1;
			}
		}
		if((g_playerRadarX != (0 - 16)) && g_playerState == 1) {
			g_playerRadarX -= 1;
			if(g_playerRadarX == 112 && g_radarScreenX != 0) {
				g_playerRadarX += 1;
				g_radarScreenX -= 1;
				g_islandXS_r += 1;
				g_islandXE_r += 1;
			}
		}
		g_playerAnimState = 8;
		g_playerFlipH = attr1_hflip;
		g_playerFlipV = 0;
	} else if(key_is_pressed(BUTTON_UP)) {
		if((g_playerY != 0) && g_playerState == 0) {
			g_playerY -= 1;
			if(g_playerY == 62 && g_screenY != 0) {
				g_playerY += 1;
				g_screenY -= 1;
				g_islandYS_p += 1;
				g_islandYE_p += 1;
			}
		}
		if((g_playerRadarY != (0 - 16)) && g_playerState == 1) {
			g_playerRadarY -= 1;
			if(g_playerRadarY == 62 && g_radarScreenY != 0) {
				g_playerRadarY += 1;
				g_radarScreenY -= 1;
				g_islandYS_r += 1;
				g_islandYE_r += 1;
			}
		}
		g_playerAnimState = 0;
		g_playerFlipH = 0;
		g_playerFlipV = 0;
	} else if(key_is_pressed(BUTTON_DOWN)) {
		if((g_playerY != 144) && g_playerState == 0) {
			g_playerY += 1;
			if(g_playerY == 80 && g_screenY != (256 - 160)) {
				g_playerY -= 1;
				g_screenY += 1;
				g_islandYS_p -= 1;
				g_islandYE_p -= 1;
			}
		}
		if((g_playerRadarY != 144) && g_playerState == 1) {
			g_playerRadarY += 1;
			if(g_playerRadarY == 80 && g_radarScreenY != (256 - 160)) {
				g_playerRadarY -= 1;
				g_radarScreenY += 1;
				g_islandYS_r -= 1;
				g_islandYE_r -= 1;
			}
		}
		g_playerAnimState = 0;
		g_playerFlipH = 0;
		g_playerFlipV = attr1_vflip;
	}
	if(key_start_pressing(BUTTON_A)) {
		if(g_playerState == 0) {
			if((g_playerX >= g_islandXS_p && g_playerX <= g_islandXE_p) && (g_playerY >= g_islandYS_p && g_playerY <= g_islandYE_p)) {
				g_island->attr0 = attr0_build(attr0_Y(g_islandYS_p), attr0_hide, attr0_normal, 0, attr0_4bpp, attr0_square);
				IO_DISPCNT = 0;
				while(1);
			}
		}
	}
}
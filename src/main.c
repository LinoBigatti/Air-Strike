#include <basics/types.h>
#include <input.h>
#include <object.h>

#include "time.h"
#include "gfx.h"

int main(void) {
	setup_gfx();
	
	while(1) {
		key_update();
		
		if(key_is_pressed(BUTTON_RIGHT)) {
			g_playerX += 1;
			g_playerAnimState = 8;
			g_playerFlipH = 0;
			g_playerFlipV = 0;
		} else if(key_is_pressed(BUTTON_LEFT)) {
			g_playerX -= 1;
			g_playerAnimState = 8;
			g_playerFlipH = attr1_hflip;
			g_playerFlipV = 0;
		} else if(key_is_pressed(BUTTON_UP)) {
			g_playerY -= 1;
			g_playerAnimState = 0;
			g_playerFlipH = 0;
			g_playerFlipV = 0;
		} else if(key_is_pressed(BUTTON_DOWN)) {
			g_playerY += 1;
			g_playerAnimState = 0;
			g_playerFlipH = 0;
			g_playerFlipV = attr1_vflip;
		}
		
		update_timer();
		update_gfx();
	}
	
	return 0;
}

#include <basics/types.h>
#include <input.h>

#include "gfx.h"
#include "control.h"
#include "time.h"
#include "rng.h"

int main(void) {
	while(key_is_not_pressed(BUTTON_START)) {
		key_update();
		update_timer();
	}
	g_islandXE = (g_islandXS = random_range(0, 240)) + 32;
	g_islandYE = (g_islandYS = random_range(0, 128)) + 32;
	setup_gfx();
	
	while(1) {
		handle_input();
		update_timer();
		update_gfx();
	}
	
	return 0;
}

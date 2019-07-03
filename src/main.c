#include <basics/types.h>
#include <basics/window.h>
#include <input.h>

#include "selectLanguage.h"
#include "gfx.h"
#include "control.h"
#include "time.h"
#include "rng.h"

int main(void) {
	select_language();
	
	while(key_is_not_pressed(BUTTON_START)) {
		key_update();
		update_timer();
	}
	
	g_islandXE_p = g_islandXE_r = (g_islandXS_p = g_islandXS_r = random_range(0, 208)) + 32;
	g_islandYE_p = g_islandYE_r = (g_islandYS_p = g_islandYS_r = random_range(0, 118)) + 32;
	setup_gfx();
	
	while(1) {
		handle_input();
		update_timer();
		update_gfx();
	}
	
	return 0;
}

//Time functions.

#include "time.h"

void update_timer(void) {
	Vsync();
	
	g_absoluteFrames++;
	g_relativeFrames++;
	
	random_set_seed(g_absoluteFrames);
	random();
	
	if(g_relativeFrames == 60) {
		g_relativeFrames = 0;
		g_seconds++;
		if(g_seconds == 60) {
			g_seconds = 0;
			g_minutes++;
			if(g_minutes == 60) {
				g_minutes = 0;
				g_hours++;
			}
		}
	}
}

void reset_timer(void) {
	g_relativeFrames = 0;
	g_seconds = 0;
	g_minutes = 0;
	g_hours = 0;
}

void hard_reset_timer(void) {
	g_absoluteFrames = 0;
	g_relativeFrames = 0;
	g_seconds = 0;
	g_minutes = 0;
	g_hours = 0;
}

void delay(u32 seconds) {
	u32 frames_ = 0;
	u32 seconds_ = 0;
	
	while(seconds_ != seconds) {
		Vsync();
		frames_++;
		
		if(frames_ == 60) {
			frames_ = 0;
			seconds_++;
		}
	}
}

//{{BLOCK(win_screen)

//======================================================================
//
//	win_screen, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 102 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 6528 + 2048 = 9088
//
//	Time-stamp: 2019-07-03, 14:03:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WIN_SCREEN_H
#define GRIT_WIN_SCREEN_H

#define win_screenTilesLen 6528
extern const unsigned short win_screenTiles[3264];

#define win_screenMapLen 2048
extern const unsigned short win_screenMap[1024];

#define win_screenPalLen 512
extern const unsigned short win_screenPal[256];

#endif // GRIT_WIN_SCREEN_H

//}}BLOCK(win_screen)

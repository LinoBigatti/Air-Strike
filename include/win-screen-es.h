
//{{BLOCK(win_screen_es)

//======================================================================
//
//	win_screen_es, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 132 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 8448 + 2048 = 11008
//
//	Time-stamp: 2019-07-03, 15:35:32
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WIN_SCREEN_ES_H
#define GRIT_WIN_SCREEN_ES_H

#define win_screen_esTilesLen 8448
extern const unsigned short win_screen_esTiles[4224];

#define win_screen_esMapLen 2048
extern const unsigned short win_screen_esMap[1024];

#define win_screen_esPalLen 512
extern const unsigned short win_screen_esPal[256];

#endif // GRIT_WIN_SCREEN_ES_H

//}}BLOCK(win_screen_es)

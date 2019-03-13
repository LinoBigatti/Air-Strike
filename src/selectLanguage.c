#include "selectLanguage.h"

void select_language(void) {
	if(read_8(0) == 0xFF) {
		char lenguage = 's';;
		obj_clear_all();
		obj_attributes *selection1 = &obj_reg_memory[0];
		obj_attributes *selection2 = &obj_reg_memory[1];
		
		bg_palette_32(select_languagePal, select_languagePalLen / 4, 0);
		bg_tileset_32(select_languageTiles, select_languageTilesLen / 4, 0, 8);
		bg_map_32(select_languageMap, select_languageMapLen / 4, 31);
		
		obj_palette_32(selection1Pal, selection1PalLen / 4, 0);
		obj_tiles_32(selection1Tiles, selection1TilesLen / 4, 4, 0, 4);
		obj_tiles_32(selection2Tiles, selection2TilesLen / 4, 4, 32, 4);
		
		selection1->attr0 = selection2->attr0 = attr0_build(attr0_Y(107), attr0_regular, attr0_normal, 0, attr0_4bpp, attr0_horizontal_rect);
		selection1->attr1 = attr1_regular_build(attr1_X(10), 0, 0, attr1_size(OBJ_64x32));
		selection2->attr1 = attr1_regular_build(attr1_X(10 + 64), 0, 0, attr1_size(OBJ_64x32));
		selection1->attr2 = attr2_build(attr2_base_tile(0), attr2_priority(0), attr2_palbank(0));
		selection2->attr2 = attr2_build(attr2_base_tile(32), attr2_priority(0), attr2_palbank(0));
		
		IO_BG0CNT = bg0cnt_cbb(0) | bg0cnt_prio(0) | bg0cnt_sbb(31) | bg0cnt_8bpp | bg0cnt_size(BG_32x32);
		IO_DISPCNT = dispcnt_mode(0) | dispcnt_BG0 | dispcnt_OBJ | dispcnt_obj_mapping_1D;
		
		while(key_is_not_pressed(BUTTON_START)) {
			key_update();
			update_timer();
			if(key_start_pressing(BUTTON_RIGHT)) {
				selection1->attr1 = attr1_regular_build(attr1_X(126), 0, 0, attr1_size(OBJ_64x32));
				selection2->attr1 = attr1_regular_build(attr1_X(126 + 64), 0, 0, attr1_size(OBJ_64x32));
				lenguage = 'e';
			}
			if(key_start_pressing(BUTTON_LEFT)) {
				selection1->attr1 = attr1_regular_build(attr1_X(10), 0, 0, attr1_size(OBJ_64x32));
				selection2->attr1 = attr1_regular_build(attr1_X(10 + 64), 0, 0, attr1_size(OBJ_64x32));
				lenguage = 's';
			}
		}
		
		save_8(lenguage, 0);
	}
}
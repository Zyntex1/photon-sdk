#pragma once

#include "utils.h"

namespace modules {
	plat_module(tier0, "tier0.dll", "libtier0.so");
	plat_module(tier1, "vstdlib.dll", "libvstdlib.so");
}  // namespace modules

namespace offsets {
	offset(register_con_command, 9, 9);
	offset(unregister_con_command, 10, 10);
	offset(find_command_base, 13, 13);
	offset(cmd_list, 48, 48);
	offset(game_frame, 4, 4);
	offset(is_running_simulation, 12, 12);
	offset(frame, 5, 6);
	offset(eng, 2, 4);
	offset(client_cmd, 7, 7);
	offset(get_client_state, 4, 9);
	offset(set_signon_state, 15, 36);
	offset(cbuf_add_text, 46, 35);
	offset(get_active_split_screen_slot, 127, 127);
	offset(execute_client_cmd, 104, 104);
	offset(draw_set_color, 14, 13);
	offset(draw_filled_rect, 15, 15);
	offset(draw_outlined_rect, 17, 17);
	offset(draw_line, 18, 18);
	offset(draw_colored_text, 160, 160);
	offset(create_font, 69, 69);
	offset(set_font_glyph_set, 70, 70);
	offset(get_text_size, 77, 77);
	offset(draw_get_texture_id, 33, 33);
	offset(draw_set_texture_file, 35, 35);
	offset(draw_set_texture_rgba, 36, 36);
	offset(draw_set_texture, 37, 37);
	offset(draw_get_texture_size, 38, 38);
	offset(draw_textured_rect, 39, 39);
	offset(is_texture_id_valid, 40, 40);
	offset(create_new_texture_id, 41, 41);
	offset(get_screen_size, 42, 42);
	offset(paint, 14, 15);
	offset(paint_traverse_ex, 117, 117);
	offset(start_drawing, 127, 1341);
	offset(finish_drawing, 603, 355);
	offset(enable_input, 10, 10);
	offset(is_button_down, 14, 14);
	offset(get_cursor_position, 45, 45);
}  // namespace offsets

namespace signatures {
	signature(create, "55 8B EC 8B 45 0C 56 8B F1 89 76 1C", "57 BA ? ? ? ? 56");
	signature(dtor, "55 8B EC 56 8B F1 8B 46 24", "53 83 EC 08 8B 5C 24 10 8B 43 24");
}  // namespace signatures

namespace symbols {
	symbol(msg, "Msg", "Msg");
	symbol(color_msg, "?ConColorMsg@@YAXABVColor@@PBDZZ", "_Z11ConColorMsgRK5ColorPKcz");
	symbol(warning, "Warning", "Warning");
	symbol(dev_msg, "?DevMsg@@YAXPBDZZ", "_Z6DevMsgPKcz");
	symbol(dev_warning, "?DevWarning@@YAXPBDZZ", "_Z10DevWarningPKcz");
}  // namespace symbols
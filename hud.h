#pragma once

#include "source_sdk.h"

#include <string>

struct bounds_t {
	int top;
	int left;
	int bottom;
	int right;
};

namespace wh_api {
	class hud_t {
	public:
		sdk::vec2_t pos;
		sdk::vec2_t anchor;
		float scale;
		bounds_t bounds;

	protected:
		__forceinline void update_bounds(int x, int y, int w, int h) {
			if (bounds.top < y) bounds.top = pos.y + y;
			if (bounds.left < x) bounds.left = pos.x + x;
			if (bounds.bottom < y + h) bounds.bottom = pos.y + y + h;
			if (bounds.right < x + w) bounds.right = pos.x + x + w;
		}

		__forceinline void reset_bounds() {
			bounds.top = 0;
			bounds.left = 0;
			bounds.bottom = 0;
			bounds.right = 0;
		}
	};

	class i_hud : public hud_t {
	public:
		virtual void paint() = 0;
		virtual const char *get_name() = 0;
	};

	class i_thud {
	public:
		sdk::vec2_t pos;
		sdk::vec2_t anchor;
		float scale;
		sdk::h_font font;

		virtual const char *get_text() = 0;
		virtual const char *get_name() = 0;
	};
}  // namespace wh_api

class c_huds {
public:
	virtual void reg(wh_api::i_hud *hud);
	virtual void reg(wh_api::i_thud *thud);
	virtual void unreg(wh_api::i_hud *hud);
	virtual void unreg(wh_api::i_thud *thud);
};

#define filled_rect(_x, _y, w, h, color) \
	update_bounds(_x, _y, w, h);            \
	wh->render->draw_filled_rect(pos.x + _x, pos.y + _y, w, h, color);

#define outlined_rect(_x, _y, w, h, color) \
	update_bounds(_x, _y, w, h);              \
	wh->render->draw_outlined_rect(pos.x + _x, pos.y + _y, w, h, color);

#define line(_x, _y, w, h, color) \
	update_bounds(_x, _y, w, h);     \
	wh->render->draw_line(pos.x + _x, pos.y + _y, w, h, color);

#define init_font(font, font_name, size, bold, flags) \
	wh->render->create_font(font, font_name, size, bold, flags);

#define text(_x, _y, font, color, center, text)                        \
	{                                                                     \
		auto size = wh->render->get_text_size(font, text);                   \
		update_bounds(_x, _y, x + size.x, y + size.y);                       \
		wh->render->text(pos.x + _x, pos.y + _y, font, color, center, text); \
	}

#define text_size(font, text) \
	wh->render->get_text_size(font, text);

#define texture(_x, _y, w, h, texture, color) \
	update_bounds(_x, _y, w, h);                 \
	wh->render->draw_texture(pos.x + _x, pos.y + _y, w, h, texture, color);

#define screen_size() \
	wh->render->get_screen_size();
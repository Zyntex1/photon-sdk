#pragma once

#include "source_sdk.h"

class c_input {
public:
	virtual void poll_input();

	virtual bool get_key_held(unsigned int code);
	virtual bool get_key_release(unsigned int code);
	virtual bool get_key_press(unsigned int code);

	virtual sdk::vec2_t get_cursor_position();
};
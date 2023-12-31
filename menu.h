#pragma once

#include "source_sdk.h"

#include <cstddef>

class c_menu {
public:
	virtual bool button( sdk::vec2_t size, const char *label );                                                    // Returns true on button click.
	virtual bool checkbox( bool &val, const char *label );                                                         // Checkbox using boolean value.
	virtual void slider( int &val, int min, int max, const char *label );                                          // Slider using integer values.
	virtual void sliderf( float &val, float min, float max, const char *label );                                   // Slider using float values.
	virtual void colorpicker( sdk::color_t &val, const char *label );                                              // Colorpicker using a 4 value datatype (R, G, B, A).
	virtual void combo( std::size_t &val, const char *items[], std::size_t items_count, const char *label );       // Value is the index of the selected element.
	virtual void multicombo( std::size_t &val, const char *items[], std::size_t items_count, const char *label );  // Value is a bitmask containing selected elements.
};

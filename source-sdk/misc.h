#pragma once

namespace sdk {
	enum signonstate {
		signonstate_none = 0,
		signonstate_challenge = 1,
		signonstate_connected = 2,
		signonstate_new = 3,
		signonstate_prespawn = 4,
		signonstate_spawn = 5,
		signonstate_full = 6,
		signonstate_changelevel = 7,
	};

	typedef unsigned long h_font;

	enum paint_mode_t {
		paint_uipanels = (1 << 0),
		paint_ingamepanels = (1 << 1),
	};
}  // namespace sdk
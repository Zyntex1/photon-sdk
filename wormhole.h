#pragma once

#include "convar.h"
#include "events.h"
#include "hook.h"
#include "hud.h"
#include "input.h"
#include "interfaces.h"
#include "render.h"
#include "source_sdk.h"
#include "utils.h"

namespace wh_api {
	class c_shared {
	public:
		c_portal2 *portal2;
		c_hook *hook;
		c_events *events;
		c_huds *huds;
		c_render *render;
		c_input *input;
	};

	class i_wormhole_mod {
	public:
		virtual bool load(c_shared *wh) = 0;
		virtual void unload() = 0;
		virtual void on_event(const char *msg) = 0;
		virtual const char *get_name() = 0;
	};
}  // namespace wh_api

extern wh_api::c_shared *wh;

#define expose_wormhole_mod(class_t, name) \
	dll_export class_t *create_mod() {        \
		return static_cast<class_t *>(&name);    \
	}
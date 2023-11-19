#pragma once

#include "source_sdk.h"

#include <unordered_map>

class c_convar {
private:
	std::unordered_map<const char *, sdk::con_var *> convars;
	std::unordered_map<const char *, sdk::con_command *> concmds;

public:
	//	expand this later by adding overloads etc

	virtual sdk::con_var *create_convar( const char *name, const char *default_value, int flags, const char *help_string, bool has_min, float min, bool has_max, float max );  //	Create ConVars.
	virtual void destruct_convar( const char *name );                                                                                                                          //	Destruct ConVars.

	virtual sdk::con_command *create_concmd( const char *name, sdk::fn_command_callback_t cbk, const char *help_string, int flags = 0 );  //	Create ConCommands.
	virtual void destruct_concmd( const char *name );                                                                                     //	Destruct ConCommands.

	virtual void hook_cmd( const char *name, sdk::fn_command_callback_t detour, sdk::fn_command_callback_t &original );  //	Replace ConCommand callback to your own.
	virtual void unhook_cmd( const char *name, sdk::fn_command_callback_t original );                                    //	Revert ConCommand callback.
};

#define concmd_cbk( name ) \
	static void name##_cbk( const sdk::c_command &args )

#define decl_hk_cmd( name )              \
	inline sdk::fn_command_callback_t name; \
	static void name##_hk( const sdk::c_command &args )

#define hk_cmd_fn( name ) \
	void name##_hk( const sdk::c_command &args )

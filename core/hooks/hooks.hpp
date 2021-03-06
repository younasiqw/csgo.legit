#pragma once
namespace hooks {
	extern std::unique_ptr<vmt_hook> clientmode_hook;
	extern std::unique_ptr<vmt_hook> panel_hook;
	extern std::unique_ptr<vmt_hook> renderview_hook;
	extern std::unique_ptr<vmt_hook> surface_hook;

	extern WNDPROC wndproc_original;

	void initialize();
	void shutdown();

	using create_move_fn = bool(__thiscall*)(i_client_mode*, float, c_usercmd*);
	using paint_traverse_fn = void(__thiscall*)(i_panel*, unsigned int, bool, bool);
	using scene_end_fn = void(__thiscall*)(void*);
	using lock_cursor_fn = void(__thiscall*)(void*);

	bool __stdcall create_move(float frame_time, c_usercmd* user_cmd);
	void __stdcall paint_traverse(unsigned int panel, bool force_repaint, bool allow_force);
	void __stdcall scene_end();
	void __stdcall lock_cursor();

	LRESULT __stdcall wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
}
namespace cfg {
	extern bool visuals_enabled;
	extern int aimbot_smooth;
	extern bool player_name;
	extern bool player_health;
	extern bool rcs;
	extern bool player_weapon;
	extern bool aimbot;
	extern int aimbot_fov;
	extern bool cham_xqz;
	extern bool chams;
	extern int chams_combo;
	extern bool bunnyhop;
	extern bool lagcomp;
	extern bool clantag;
	extern bool player_box;
}
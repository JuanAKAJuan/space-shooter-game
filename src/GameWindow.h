#pragma once
#include "raylib.h"

class GameWindow {
public:
	GameWindow();
	void create_window();
	void update_draw_frame(void);
	void close_window();
	bool should_close();

private:
	static constexpr int SCREEN_WIDTH = 900;
	static constexpr int SCREEN_HEIGHT = 1280;
};

#pragma once
#include <raylib.h>

class Renderer {
public:
	Renderer();
	void create_window();
	void update_camera();
	void draw();
	bool should_close();
	void close_window();

private:
	static constexpr int SCREEN_WIDTH = 1280;
	static constexpr int SCREEN_HEIGHT = 720;
	Camera2D camera;
};

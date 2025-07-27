#pragma once
#include "spaceship.h"
#include <raylib.h>

class Spaceship; // Forward declaration

class Renderer {
public:
	static constexpr int SCREEN_WIDTH = 1280;
	static constexpr int SCREEN_HEIGHT = 720;

	Renderer();
	void create_window();
	void update_camera();
	void draw(const Spaceship& spaceship);
	bool should_close();
	void close_window();

private:
	Camera2D m_camera;
};

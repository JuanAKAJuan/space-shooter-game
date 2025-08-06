#pragma once

#include <raylib.h>

// Forward declaration
class Spaceship;
class EnemyManager;

class Renderer {
public:
	static constexpr int SCREEN_WIDTH = 1280;
	static constexpr int SCREEN_HEIGHT = 720;

	Renderer();
	void create_window();
	void update_camera();
	void draw(const Spaceship& spaceship, const EnemyManager& enemy_manager);
	bool should_close();
	void close_window();

private:
	Camera2D m_camera;
};

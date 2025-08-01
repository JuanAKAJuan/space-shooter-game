#include "renderer.h"
#include <algorithm>

Renderer::Renderer() {}

void Renderer::create_window() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter Game");

	int primary_monitor = 0;
	SetWindowMonitor(primary_monitor);

	SetTargetFPS(60);
	update_camera();
}

void Renderer::update_camera() {
	float scaleX = static_cast<float>(GetScreenWidth()) / SCREEN_WIDTH;
	float scaleY = static_cast<float>(GetScreenHeight()) / SCREEN_HEIGHT;
	float scale = std::min(scaleX, scaleY);

	m_camera.target = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
	m_camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	m_camera.rotation = 0.0f;
	m_camera.zoom = scale;
}

void Renderer::draw(const Spaceship& spaceship) {
	update_camera();

	BeginDrawing();
	{
		ClearBackground(BLACK);

		BeginMode2D(m_camera);
		{
			DrawRectangle(static_cast<int>(spaceship.get_x()), static_cast<int>(spaceship.get_y()),
						  static_cast<int>(spaceship.get_width()), static_cast<int>(spaceship.get_height()), WHITE);
		}
		EndMode2D();
	}
	EndDrawing();
}

bool Renderer::should_close() { return WindowShouldClose(); }

void Renderer::close_window() { CloseWindow(); }

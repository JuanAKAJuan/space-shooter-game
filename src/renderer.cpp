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

	camera.target = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
	camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = scale;
}

void Renderer::draw() {
	update_camera();

	BeginDrawing();
	{
		Color background_color = {11, 11, 11, 255};
		ClearBackground(background_color);

		BeginMode2D(camera);
		{
			DrawText("Game goes here guy.", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 20, LIGHTGRAY);
		}
		EndMode2D();
	}
	EndDrawing();
}

bool Renderer::should_close() { return WindowShouldClose(); }

void Renderer::close_window() { CloseWindow(); }

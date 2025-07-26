#include "renderer.h"
#include <raylib.h>

Renderer::Renderer() {}

void Renderer::create_window() {
	int primary_monitor = 0;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter Game");
	SetTargetFPS(60);
	SetWindowMonitor(primary_monitor);
}

bool Renderer::should_close() { return WindowShouldClose(); }

void Renderer::draw() {
	BeginDrawing();
	{
		ClearBackground(BLACK);
		DrawText("Game goes here guy.", static_cast<int>(SCREEN_WIDTH / 2), static_cast<int>(SCREEN_HEIGHT / 2), 20,
				 LIGHTGRAY);
	}
	EndDrawing();
}

void Renderer::close_window() { CloseWindow(); }

#include "GameWindow.h"
#include <raylib.h>

GameWindow::GameWindow() {}

void GameWindow::create_window() {
	int primary_monitor = 0;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter Game");
	SetTargetFPS(60);
	SetWindowMonitor(primary_monitor);
}

void GameWindow::update_draw_frame(void) {
	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}

void GameWindow::close_window() { CloseWindow(); }

bool GameWindow::should_close() { return WindowShouldClose(); }

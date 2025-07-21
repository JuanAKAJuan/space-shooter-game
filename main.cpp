#include "raylib.h"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 450;

void UpdateDrawFrame(void);

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter Game");

	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose()) {
		UpdateDrawFrame();
	}

	CloseWindow();
}

void UpdateDrawFrame(void) {
	BeginDrawing();

	ClearBackground(BLACK);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}

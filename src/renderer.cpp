#include "renderer.h"
#include "enemy_manager.h"
#include "spaceship.h"
#include <algorithm>

Renderer::Renderer() {}

void Renderer::create_window() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter Game");

	int primary_monitor {0};
	SetWindowMonitor(primary_monitor);

	SetTargetFPS(60);
	update_camera();
}

void Renderer::update_camera() {
	float scaleX {static_cast<float>(GetScreenWidth()) / SCREEN_WIDTH};
	float scaleY {static_cast<float>(GetScreenHeight()) / SCREEN_HEIGHT};
	float scale {std::min(scaleX, scaleY)};

	m_camera.target = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
	m_camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	m_camera.rotation = 0.0f;
	m_camera.zoom = scale;
}

void Renderer::draw(const Spaceship& spaceship, const EnemyManager& enemy_manager) {
	update_camera();

	BeginDrawing();
	{
		ClearBackground(BLACK);

		BeginMode2D(m_camera);
		{
			// Draw spaceship
			DrawRectangle(static_cast<int>(spaceship.get_x()), static_cast<int>(spaceship.get_y()),
						  static_cast<int>(spaceship.get_width()), static_cast<int>(spaceship.get_height()), WHITE);

			// Draw enemies
			for (const Enemy& enemy : enemy_manager.get_enemies()) {
				if (enemy.is_alive()) {
					DrawRectangle(static_cast<int>(enemy.get_x()), static_cast<int>(enemy.get_y()),
								  static_cast<int>(enemy.get_width()), static_cast<int>(enemy.get_height()), RED);
				}
			}
		}
		EndMode2D();

		draw_lives_ui(spaceship.get_lives());
	}
	EndDrawing();
}

bool Renderer::should_close() { return WindowShouldClose(); }

void Renderer::close_window() { CloseWindow(); }

void Renderer::draw_lives_ui(int lives) {
	const int UI_MARGIN {20};
	const int SCALE_FACTOR {4};
	const int HEART_WIDTH {8 * SCALE_FACTOR};
	const int HEART_SPACING {HEART_WIDTH + 10};

	// clang-format off
    int heart_pattern[8][8] {
        {0, 1, 1, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
	  };
	// clang-format on

	for (int life {0}; life < lives; ++life) {
		int heart_x {UI_MARGIN + (life * HEART_SPACING)};
		int heart_y {UI_MARGIN};

		for (int row {0}; row < 8; ++row) {
			for (int col {0}; col < 8; ++col) {
				if (heart_pattern[row][col]) {
					DrawRectangle(heart_x + col * SCALE_FACTOR, heart_y + row * SCALE_FACTOR, SCALE_FACTOR,
								  SCALE_FACTOR, RED);
				}
			}
		}
	}
}

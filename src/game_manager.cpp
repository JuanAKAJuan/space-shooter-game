#include "game_manager.h"
#include <raylib.h>

void GameManager::run() {
	SetTraceLogLevel(LOG_WARNING);
	renderer.create_window();

	while (!renderer.should_close() && spaceship.get_lives() > 0) {
		InputHandler::Direction direction {input_handler.get_movement_direction()};
		spaceship.update(direction, GetFrameTime());
		enemy_manager.update(GetFrameTime());

		if (check_collision_with_enemies()) {
			handle_player_death();
		}

		renderer.draw(spaceship, enemy_manager);
	}

	renderer.close_window();
}

bool GameManager::check_collision_with_enemies() {
	const auto& enemies {enemy_manager.get_enemies()};

	for (const auto& enemy : enemies) {
		if (enemy.is_alive() &&
			rectangles_collide(spaceship.get_x(), spaceship.get_y(), spaceship.get_width(), spaceship.get_height(),
							   enemy.get_x(), enemy.get_y(), enemy.get_width(), enemy.get_height())) {
			return true;
		}
	}
	return false;
}

void GameManager::handle_player_death() {
	if (!spaceship.decrease_lives()) {
		// Game over
		return;
	}

	// Player is still alive
}

bool GameManager::rectangles_collide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	// Calculate the edges of both rectangles
	float left1 {x1};
	float right1 {x1 + w1};
	float top1 {y1};
	float bottom1 {y1 + h1};

	float left2 {x2};
	float right2 {x2 + w2};
	float top2 {y2};
	float bottom2 {y2 + h2};

	// Check if rectangles are NOT overlapping (easier to understand)
	// If any of these conditions is true, they don't overlap
	if (right1 <= left2) {
		return false; // Rectangle 1 is to the left of rectangle 2
	}
	if (left1 >= right2) {
		return false; // Rectangle 1 is to the right of rectangle 2
	}
	if (bottom1 <= top2) {
		return false; // Rectangle 1 is above rectangle 2
	}
	if (top1 >= bottom2) {
		return false; // Rectangle 1 is below rectangle 2
	}

	return true;
}

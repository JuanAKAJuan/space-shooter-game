#include "game_manager.h"
#include <raylib.h>

void GameManager::run() {
	SetTraceLogLevel(LOG_WARNING);

	renderer.create_window();

	while (!renderer.should_close()) {
		InputHandler::Direction direction = input_handler.get_movement_direction();
		spaceship.update(direction, GetFrameTime());
		enemy_manager.update(GetFrameTime());

		renderer.draw(spaceship, enemy_manager);
	}

	renderer.close_window();
}

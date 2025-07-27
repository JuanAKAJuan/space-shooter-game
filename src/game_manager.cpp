#include "game_manager.h"
#include <raylib.h>

void GameManager::run() {
	renderer.create_window();

	while (!renderer.should_close()) {
		InputHandler::Direction direction = input_handler.get_movement_direction();
		spaceship.update(direction, GetFrameTime());

		renderer.draw(spaceship);
	}

	renderer.close_window();
}

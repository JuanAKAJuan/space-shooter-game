#include "game_manager.h"

void GameManager::run() {
	renderer.create_window();

	while (!renderer.should_close()) {
		renderer.draw();
	}

	renderer.close_window();
}

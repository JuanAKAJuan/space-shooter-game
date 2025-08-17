#include "input_handler.h"

InputHandler::Direction InputHandler::get_movement_direction() {
	bool left_pressed {IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)};
	bool right_pressed {IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)};

	if (left_pressed && !right_pressed) {
		return Direction::LEFT;
	} else if (right_pressed && !left_pressed) {
		return Direction::RIGHT;
	}

	return Direction::NONE;
}

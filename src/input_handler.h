#pragma once
#include <raylib.h>

class InputHandler {
public:
	enum class Direction { NONE, LEFT, RIGHT };
	Direction get_movement_direction();
};

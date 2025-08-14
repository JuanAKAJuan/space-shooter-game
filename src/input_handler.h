#pragma once
#include <raylib.h>

/**
 * @brief Handles user input for the game
 *
 * This class is responsible for processing keyboard input and translating
 * it into game actions, particularly player movement directions.
 */
class InputHandler {
public:
	/**
	 * @brief Enumeration representing possible movement directions
	 */
	enum class Direction {
		NONE, ///< No movement input detected
		LEFT, ///< Left movement input detected
		RIGHT ///< Right movement input detected
	};

	/**
	 * @brief Gets the current movement direction based on user input
	 *
	 * Checks for keyboard input and determines the direction the player
	 * wants to move their spaceship.
	 *
	 * @return Direction The current movement direction (NONE, LEFT, or RIGHT)
	 */
	Direction get_movement_direction();
};

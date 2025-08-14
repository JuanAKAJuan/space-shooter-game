#pragma once

#include "enemy_manager.h"
#include "input_handler.h"
#include "renderer.h"
#include "spaceship.h"

/**
 * @class GameManager
 * @brief Main game controller that manages the game loop and coordinates all game components
 *
 * The GameManager class serves as the central controller for the game.
 * It orchestrates the interaction between different game systems including rendering,
 * input handling, player spaceship, and enemy management. This class implements the
 * main game loop and manages the overall game state.
 */
class GameManager {
public:
	/**
	 * @brief Starts and runs the main game loop
	 *
	 * Initializes the game window, runs the main game loop which handles input,
	 * updates game objects, and renders the scene. The loop continues until the
	 * user closes the window. Also handles cleanup when the game ends.
	 */
	void run();

private:
	Renderer renderer;			///< Handles all rendering operations and window management
	InputHandler input_handler; ///< Processes user input and converts to game actions
	Spaceship spaceship;		///< Player-controlled spaceship object
	EnemyManager enemy_manager; ///< Manages enemy spawning, behavior, and lifecycle
};

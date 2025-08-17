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

	/**
	 * @brief Checks for collisions between the spaceship and enemies
	 * @return true if collision detected, false otherwise
	 */
	bool check_collision_with_enemies();

	/**
	 * @brief Handles player death logic
	 */
	void handle_player_death();

	/**
	 * @brief Checks if two rectangles are colliding using AABB collision detection
	 * @param x1, y1, w1, h1 First rectangle parameters
	 * @param x2, y2, w2, h2 Second rectangle parameters
	 * @return true if rectangles overlap, false otherwise
	 */
	bool rectangles_collide(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
};

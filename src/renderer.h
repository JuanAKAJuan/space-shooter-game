#pragma once

#include <raylib.h>

// Forward declaration
class Spaceship;
class EnemyManager;

/**
 * @brief Handles rendering operations and window management for the game
 *
 * The Renderer class is responsible for initializing the game window,
 * managing the 2D camera, and drawing all game objects to the screen.
 * It provides a centralized rendering interface for the game engine.
 */
class Renderer {
public:
	static constexpr int SCREEN_WIDTH = 1280; ///< Width of the game window in pixels
	static constexpr int SCREEN_HEIGHT = 720; ///< Height of the game window in pixels

	/**
	 * @brief Constructs a new Renderer object
	 */
	Renderer();

	/**
	 * @brief Initializes and creates the game window
	 */
	void create_window();

	/**
	 * @brief Updates the camera state for the current frame
	 */
	void update_camera();

	/**
	 * @brief Renders all game objects to the screen
	 * @param spaceship The player's spaceship to render
	 * @param enemy_manager The enemy manager containing all enemies to render
	 */
	void draw(const Spaceship& spaceship, const EnemyManager& enemy_manager);

	/**
	 * @brief Checks if the window should be closed
	 * @return true if the window close event was triggered, false otherwise
	 */
	bool should_close();

	/**
	 * @brief Closes the game window and cleans up resources
	 */
	void close_window();

private:
	Camera2D m_camera; ///< 2D camera for rendering the game world
};

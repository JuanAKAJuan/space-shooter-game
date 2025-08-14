#pragma once
#include "input_handler.h"

/**
 * @brief Represents the player-controlled spaceship
 *
 * The Spaceship class manages the player's spacecraft, including its position,
 * movement, and boundaries. It responds to player input and handles collision
 * detection with screen boundaries.
 */
class Spaceship {
public:
	/**
	 * @brief Constructs a new Spaceship object with default position and properties
	 */
	Spaceship();

	/**
	 * @brief Updates the spaceship's position based on input and delta time
	 * @param direction The movement direction from input handler
	 * @param delta_time Time elapsed since the last frame in seconds
	 */
	void update(InputHandler::Direction direction, float delta_time);

	/**
	 * @brief Gets the current x-coordinate of the spaceship
	 * @return Current x-coordinate position
	 */
	float get_x() const { return m_x; };

	/**
	 * @brief Gets the current y-coordinate of the spaceship
	 * @return Current y-coordinate position
	 */
	float get_y() const { return m_y; };

	/**
	 * @brief Gets the width of the spaceship
	 * @return Width of the spaceship in pixels
	 */
	float get_width() const { return m_width; };

	/**
	 * @brief Gets the height of the spaceship
	 * @return Height of the spaceship in pixels
	 */
	float get_height() const { return m_height; };

private:
	float m_x, m_y;			 ///< Spaceship position coordinates
	float m_width, m_height; ///< Spaceship dimensions in pixels
	float m_speed;			 ///< Movement speed in pixels per second
	float m_screen_width;	 ///< Screen width for boundary checking
};

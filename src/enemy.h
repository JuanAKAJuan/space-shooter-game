#pragma once

/**
 * @class Enemy
 * @brief Represents an enemy entity in the game
 *
 * The Enemy class manages individual enemy entities, including their position,
 * dimensions, and lifecycle. Enemies move in formation and can be destroyed
 * when hit by player projectiles.
 */
class Enemy {
public:
	/**
	 * @brief Constructs a new Enemy object
	 * @param x Initial x-coordinate position
	 * @param y Initial y-coordinate position
	 */
	Enemy(float x, float y);

	/**
	 * @brief Updates the enemy's position based on formation movement
	 * @param delta_time Time elapsed since last frame in seconds
	 * @param formation_speed_x Horizontal speed of the enemy formation
	 * @param formation_speed_y Vertical speed of the enemy formation
	 */
	void update(float delta_time, float formation_speed_x, float formation_speed_y);

	/**
	 * @brief Gets the current x-coordinate of the enemy
	 * @return Current x-coordinate position
	 */
	float get_x() const { return m_x; }

	/**
	 * @brief Gets the current y-coordinate of the enemy
	 * @return Current y-coordinate position
	 */
	float get_y() const { return m_y; }

	/**
	 * @brief Gets the width of the enemy
	 * @return Width of the enemy in pixels
	 */
	float get_width() const { return m_width; }

	/**
	 * @brief Gets the height of the enemy
	 * @return Height of the enemy in pixels
	 */
	float get_height() const { return m_height; }

	/**
	 * @brief Checks if the enemy is alive
	 * @return true if the enemy is alive, false otherwise
	 */
	bool is_alive() const { return m_alive; }

	/**
	 * @brief Destroys the enemy by marking it as not alive
	 */
	void destroy() { m_alive = false; }

private:
	float m_x, m_y;			 ///< Enemy position coordinates
	float m_width, m_height; ///< Enemy dimensions in pixels
	bool m_alive;			 ///< Flag indicating if the enemy is alive
};

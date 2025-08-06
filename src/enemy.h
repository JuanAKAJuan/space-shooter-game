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

	void update(float delta_time, float formation_speed_x, float formation_speed_y);
	float get_x() const { return m_x; }
	float get_y() const { return m_y; }
	float get_width() const { return m_width; }
	float get_height() const { return m_height; }
	bool is_alive() const { return m_alive; }
	void destroy() { m_alive = false; }

private:
	float m_x, m_y;
	float m_width, m_height;
	bool m_alive;
};

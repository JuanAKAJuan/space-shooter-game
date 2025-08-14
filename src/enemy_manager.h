#pragma once

#include "enemy.h"
#include <vector>

/**
 * @brief Manages a formation of enemies in the game
 *
 * The EnemyManager class handles the creation, movement, and behavior of enemy formations.
 * It manages a grid of enemies that move horizontally across the screen and drop down
 * when they reach the screen edges.
 */
class EnemyManager {
public:
	/**
	 * @brief Constructs an EnemyManager and creates the initial enemy formation
	 */
	EnemyManager();

	/**
	 * @brief Updates all enemies in the formation
	 * @param delta_time Time elapsed since the last frame in seconds
	 */
	void update(float delta_time);

	/**
	 * @brief Gets a const reference to the enemy vector
	 * @return Const reference to the vector containing all enemies
	 */
	const std::vector<Enemy>& get_enemies() const { return m_enemies; }

	/**
	 * @brief Checks if all enemies in the formation have been destroyed
	 * @return True if no enemies are alive, false otherwise
	 */
	bool all_enemies_destroyed() const;

private:
	std::vector<Enemy> m_enemies; ///< Container holding all enemies in the formation
	float m_formation_speed_x;	  ///< Current horizontal speed of the formation
	float m_formation_speed_y;	  ///< Current vertical speed of the formation
	float m_base_speed;			  ///< Base horizontal movement speed
	bool m_moving_right;		  ///< True if formation is moving right, false if moving left
	float m_drop_distance;		  ///< Distance enemies drop when changing direction

	/**
	 * @brief Creates the initial enemy formation in a grid pattern
	 */
	void create_formation();

	/**
	 * @brief Checks if the formation should change direction
	 * @return True if the formation has reached a screen edge and should change direction
	 */
	bool should_change_direction() const;

	/**
	 * @brief Changes the formation's direction and applies vertical drop
	 */
	void change_direction();

	/**
	 * @brief Finds the x-coordinate of the leftmost living enemy
	 * @return X-coordinate of the leftmost enemy, or screen width if no enemies alive
	 */
	float get_leftmost_enemy_x() const;

	/**
	 * @brief Finds the x-coordinate of the rightmost living enemy's right edge
	 * @return X-coordinate of the rightmost enemy's right edge, or 0 if no enemies alive
	 */
	float get_rightmost_enemy_x() const;
};

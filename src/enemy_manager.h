#pragma once
#include "enemy.h"
#include <vector>

class EnemyManager {
public:
	EnemyManager();
	void update(float delta_time);
	const std::vector<Enemy>& get_enemies() const { return m_enemies; }
	bool all_enemies_destroyed() const;

private:
	std::vector<Enemy> m_enemies;
	float m_formation_speed_x;
	float m_formation_speed_y;
	float m_base_speed;
	float m_drop_distance;
	bool m_moving_right;

	void create_formation();
	bool should_change_direction() const;
	void change_direction();
	float get_leftmost_enemy_x() const;
	float get_rightmost_enemy_x() const;
};

#include "enemy_manager.h"
#include "renderer.h"
#include <algorithm>

EnemyManager::EnemyManager()
	: m_formation_speed_x(0.0f), m_formation_speed_y(0.0f), m_base_speed(50.0f), m_drop_distance(30.0f),
	  m_moving_right(true) {
	create_formation();
	m_formation_speed_x = m_base_speed;
}

void EnemyManager::create_formation() {
	const int ROWS = 5;
	const int COLS = 10;
	const float ENEMY_SPACING_X = 100.0f;
	const float ENEMY_SPACING_Y = 80.0f;
	const float START_X = 100.0f;
	const float START_Y = 50.0f;

	m_enemies.clear();
	m_enemies.reserve(ROWS * COLS);

	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col) {
			float x = START_X + (col * ENEMY_SPACING_X);
			float y = START_Y + (row * ENEMY_SPACING_Y);
			m_enemies.emplace_back(x, y);
		}
	}
}

void EnemyManager::update(float delta_time) {
	if (should_change_direction()) {
		change_direction();
	}

	for (Enemy& enemy : m_enemies) {
		enemy.update(delta_time, m_formation_speed_x, m_formation_speed_y);
	}

	// Reset vertical movement after applying it.
	m_formation_speed_y = 0.0f;
}

bool EnemyManager::should_change_direction() const {
	if (m_moving_right) {
		return get_rightmost_enemy_x() >= Renderer::SCREEN_WIDTH - 30.0f;
	} else {
		return get_leftmost_enemy_x() <= 30.0f;
	}
}

void EnemyManager::change_direction() {
	m_moving_right = !m_moving_right;
	m_formation_speed_x = m_moving_right ? m_base_speed : -m_base_speed;
	m_formation_speed_y = m_drop_distance;
}

float EnemyManager::get_leftmost_enemy_x() const {
	float leftmost = Renderer::SCREEN_WIDTH;
	for (const Enemy& enemy : m_enemies) {
		if (enemy.is_alive() && enemy.get_x() < leftmost) {
			leftmost = enemy.get_x();
		}
	}
	return leftmost;
}

float EnemyManager::get_rightmost_enemy_x() const {
	float rightmost = 0.0f;
	for (const Enemy& enemy : m_enemies) {
		if (enemy.is_alive() && enemy.get_x() + enemy.get_width() > rightmost) {
			rightmost = enemy.get_x() + enemy.get_width();
		}
	}
	return rightmost;
}

bool EnemyManager::all_enemies_destroyed() const {
	return std::none_of(m_enemies.begin(), m_enemies.end(), [](const Enemy& enemy) { return enemy.is_alive(); });
}

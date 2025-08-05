#include "enemy.h"
#include "renderer.h"

Enemy::Enemy(float x, float y) : m_x(x), m_y(y), m_width(30.0f), m_height(20.0f), m_alive(true) {}

void Enemy::update(float delta_time, float formation_speed_x, float formation_speed_y) {
	if (!m_alive)
		return;

	m_x += formation_speed_x * delta_time;
	m_y += formation_speed_y * delta_time;
}

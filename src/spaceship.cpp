#include "spaceship.h"
#include "renderer.h"
#include <algorithm>

Spaceship::Spaceship()
	: m_width(20.0f), m_height(40.0f), m_speed(300.0f), m_screen_width(Renderer::SCREEN_WIDTH), m_lives(3) {
	m_x = Renderer::SCREEN_WIDTH / 2.0f - m_width / 2.0f;
	m_y = Renderer::SCREEN_HEIGHT - m_height - 40.0f; // 20px margin from bottom
}

void Spaceship::update(InputHandler::Direction direction, float delta_time) {
	float movement {m_speed * delta_time};

	switch (direction) {
		case InputHandler::Direction::LEFT:
			m_x -= movement;
			break;
		case InputHandler::Direction::RIGHT:
			m_x += movement;
			break;
		case InputHandler::Direction::NONE:
			break;
	}

	// Clamp to screen boundaries
	m_x = std::max(0.0f, std::min(m_x, m_screen_width - m_width));
}

bool Spaceship::decrease_lives() {
	if (m_lives > 0) {
		--m_lives;
	}

	return m_lives > 0;
}

void Spaceship::reset_position() {}

bool Spaceship::is_alive() { return m_lives > 0; }

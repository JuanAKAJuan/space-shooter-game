#pragma once
#include "input_handler.h"

class Spaceship {
public:
	Spaceship();
	void update(InputHandler::Direction direction, float delta_time);
	float get_x() const { return m_x; };
	float get_y() const { return m_y; };
	float get_width() const { return m_width; };
	float get_height() const { return m_height; };

private:
	float m_x, m_y;
	float m_width, m_height;
	float m_speed;
	float m_screen_width;
};

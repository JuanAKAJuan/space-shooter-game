#pragma once

class Enemy {
public:
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

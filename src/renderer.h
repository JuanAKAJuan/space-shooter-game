#pragma once

class Renderer {
public:
	Renderer();
	void create_window();
	bool should_close();
	void draw();
	void close_window();

private:
	static constexpr int SCREEN_WIDTH = 900;
	static constexpr int SCREEN_HEIGHT = 1280;
};

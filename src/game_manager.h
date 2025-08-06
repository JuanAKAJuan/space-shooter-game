#pragma once

#include "enemy_manager.h"
#include "input_handler.h"
#include "renderer.h"
#include "spaceship.h"

class GameManager {
public:
	void run();

private:
	Renderer renderer;
	InputHandler input_handler;
	Spaceship spaceship;
	EnemyManager enemy_manager;
};

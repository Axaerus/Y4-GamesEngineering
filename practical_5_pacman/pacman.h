#pragma once
#include <memory>
#include "ecm.h"
#include "cmp_actor_movement.h"
#include "cmp_sprite.h"
#include "LevelSystem.h"
#include "scene.h"
#include <SFML/Graphics.hpp>

extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;

class MenuScene : public Scene {
private:
	sf::Text text;
	sf::Font font;

public:
	MenuScene() = default;
	void update(double dt) override;
	void render() override;
	void load()override;
};

class GameScene : public Scene {
private:
	sf::Text text;
	sf::Clock scoreClock;
	std::shared_ptr<Entity> player;
	std::vector<std::shared_ptr<Entity>> ghosts;

	void respawn();

public:
	GameScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
};
#include "ghost.h"
#include "pacman.h"
#include "player.h"
#include "scene.h"
#include "system_renderer.h"

void Scene::render() { _ents.render(); }
void Scene::update(double dt) { _ents.update(dt); }

void MenuScene::update(double dt) {
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() {
	//Set up the text element here!
	sf::Font font;
	font.loadFromFile("res/fonts/COOPBL.TTF");
	text.setFont(font)
}

void GameScene::load() {
	// Load player
	auto player = std::make_unique<Player>();
	_ents.list.push_back(std::move(player));

	// Load Ghosts
	for (int x = 0; x < enemyCount; x++) {
		auto ghost = std::make_unique<Ghost>();
		_ents.list.push_back(std::move(ghost));
	}
}
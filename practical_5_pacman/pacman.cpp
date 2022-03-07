#include "pacman.h"
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
}

void GameScene::load() {
	/*
	...
		auto player = ...
		_ents.list.push_back(player);
	for (4 ghosts) {
		auto ghost = ...
			_ents.list.push_back(ghost);
	}
	...
	*/
}
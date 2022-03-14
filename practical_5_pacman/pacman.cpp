#include "ecm.h"
#include "ghost.h"
#include "pacman.h"
#include "player.h"
#include "scene.h"
#include "system_renderer.h"

#define GHOSTS_COUNT 4

using namespace sf;
using namespace std;

void Scene::render() { _ents.render(); }
void Scene::update(double dt) { _ents.update(dt); }
std::vector<std::shared_ptr<Entity>>& Scene::getEnts() { return _ents.list; }
void Scene::shutdown() {
	auto list = getEnts();
	for (auto item : list)
	{
		item->setForDelete();
	}
}

void MenuScene::load() {
	//Set up the text element here!
	font.loadFromFile("res/fonts/COOPBL.ttf");
	text.setFont(font);
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		activeScene = gameScene;
	}
	text.setString("Almost Pacman");
	text.setCharacterSize(24);
	Scene::update(dt);
}

void GameScene::load() {
	//// Load player
	//auto player = std::make_unique<Player>();
	//_ents.list.push_back(std::move(player));

	//// Load Ghosts
	//for (int x = 0; x < enemyCount; x++) {
	//	auto ghost = std::make_unique<Ghost>();
	//	_ents.list.push_back(std::move(ghost));
	//}
	{
		auto pl = make_shared<Entity>();

		auto s = pl->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(12.f);
		s->getShape().setFillColor(Color::Yellow);
		s->getShape().setOrigin(Vector2f(12.f, 12.f));

		pl->addComponent<PlayerMovementComponent>();
		
		pl->setAlive(true);
		pl->setVisible(true);
		pl->setPosition(Vector2f(12, 12));

		_ents.list.push_back(pl);
	}

	const sf::Color ghost_cols[]{ {208, 62, 25},    // red Blinky
								 {219, 133, 28},   // orange Clyde
								 {70, 191, 238},   // cyan Inky
								 {234, 130, 229} }; // pink Pinky

	for (int i = 0; i < GHOSTS_COUNT; ++i) {
		auto ghost = make_shared<Entity>();

		auto s = ghost->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(12.f);
		s->getShape().setFillColor(ghost_cols[i % 4]);
		s->getShape().setOrigin(Vector2f(12.f, 12.f));

		ghost->addComponent<EnemyAIComponent>();

		ghost->setAlive(true);
		ghost->setVisible(true);
		ghost->setPosition(Vector2f(24 * i + 12, 36));

		_ents.list.push_back(ghost);
	}
}

void GameScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void GameScene::update(double dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
}
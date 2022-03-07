#include <SFML/Graphics.hpp>
#include <iostream>
#include "ghost.h"
#include "player.h"
#include "LevelSystem.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

const int gameWidth = 1280;
const int gameHeight = 720;
const int entityCount = 5;

sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "PAC-MAN");
EntityManager em;

void load() {
	Renderer::initialise(window);

	//temp list for entity creation
	std::vector<std::shared_ptr<Entity>> temp;
	for (int x = 0; x < entityCount; x++) {
		if (x == 0) {
			auto temp_player = make_shared<Player>();
			temp_player->setPosition(Vector2f(temp_player->getDimensions().x, temp_player->getDimensions().y));
			temp.push_back(temp_player);
		}
		auto ghost = make_shared<Ghost>();
		ghost->setPosition(Vector2f(ghost->getDimensions().x * (x + 1), ghost->getDimensions().y * 2));
		temp.push_back(ghost);
	}
	em.list = temp;
}

void Update(double dt) {
	// Update entities
	em.update(dt);
}

void Render(sf::RenderWindow& window) {
	window.clear();

	// Render entities
	em.render(window);
	Renderer::render();

	window.display();
}

void Shutdown() {
	Renderer::shutdown();
	window.close();
}

int main() {
	static Clock clock;
	load();

	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				Shutdown();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			Shutdown();
		}

		Update(dt);
		Render(window);
	}
}
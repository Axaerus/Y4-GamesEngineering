#include <SFML/Graphics.hpp>
#include <iostream>
#include "ghost.h"
#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(1280, 720), "PAC-MAN");
std::vector<std::shared_ptr<Entity>> entities;

void load() {
	entities.push_back(make_shared<Player>());
}

void Update(double dt) {
	for (auto entity : entities) {
		entity->Update(dt);
	}
}

void Render(sf::RenderWindow& window) {
	window.clear();

	// Render entities
	for (auto entity : entities) {
		entity->Render(window);
	}

	window.display();
}

int main() {
	static Clock clock;
	load();

	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		Update(dt);
		Render(window);
	}
}
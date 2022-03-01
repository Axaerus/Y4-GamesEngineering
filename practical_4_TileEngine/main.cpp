#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(800, 600), "Tile Engine Demo");

void load() {
	// ...
		ls::loadLevelFile("res/levels/maze_2.txt");

	// Print the level to the console
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x, y });
		}
		cout << endl;
	}
}

void Update(const float& dt) {
	//ls::
}

void Render(RenderWindow &window) {
	ls::Render(window);
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
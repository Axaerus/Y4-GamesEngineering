#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(800, 600), "Tile Engine Demo");
std::unique_ptr<Player> player;

void load() {
	//Load level asset
	ls::loadLevelFile("res/levels/maze_2.txt");

	// Print the level to the console
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x, y });
		}
		cout << endl;
	}
	player = std::make_unique<Player>();
	player->setPosition(ls::getStartTilePosition() + Vector2(player->getDimensions().x, player->getDimensions().y));
	//cout << player->getDimensions();
}

void Update(const float& dt) {
	player->Update(dt);
}

void Render(RenderWindow &window) {
	window.clear();
	ls::Render(window);
	player->Render(window);
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
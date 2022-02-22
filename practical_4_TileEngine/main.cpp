#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(), "Tile Engine Demo");

void Update(const float& dt) {

}

void Render() {

}

int main() {
	static Clock clock;
	//Load();

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
		Render();
	}
}
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(1280, 720), "PAC-MAN");

void load() {

}

void Update() {

}

void Render() {
	window.clear();

	// Render

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
	}
}
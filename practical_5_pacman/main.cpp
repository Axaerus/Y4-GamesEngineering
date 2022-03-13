#include <SFML/Graphics.hpp>
#include <iostream>
#include "ghost.h"
#include "player.h"
#include "LevelSystem.h"
#include "pacman.h"
#include "scene.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

const int gameWidth = 1280;
const int gameHeight = 720;
const int entityCount = 5;

sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "PAC-MAN");
std::shared_ptr<Scene> gameScene;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;

// Main load
void load() {
	Renderer::initialise(window);

	menuScene.reset(new MenuScene());	// take ownership of extern
	gameScene.reset(new GameScene());	// ---
	menuScene->load();	// Load menu scene
	gameScene->load();	// Load game scene

	activeScene = gameScene;	// Establish initial scene
}

// Main update
void Update(double dt) {
	// Update entities
	activeScene->update(dt); // Updated current scene
}

// Main render
void Render(sf::RenderWindow& window) {
	window.clear();	// Clear/flush screen

	// Render entities
	activeScene->render();	// Pushes entities to renderer
	Renderer::render();		// Renders entities handed over from entity manager

	window.display();	//	Display the screen
}

// General shutdown method
void Shutdown() {
	activeScene->shutdown();
	Renderer::shutdown();	// Flush renderer sprite pool
	window.close();	// Close window
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
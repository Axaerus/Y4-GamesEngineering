#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
sf::Clock clock;

const Keyboard::Key controls[4] = {
    Keyboard::A, //Move player 1 up
    Keyboard::Z, //Move player 1 down
    Keyboard::Up, //Move player 2 up
    Keyboard::Down //Move player 2 down
};

const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f


void Update(double dt){
	// Update Everything
}

void Render(){
	// Draw everthing
    window.display();
}

int main(){
  //initialise and load
    window.setVerticalSyncEnabled(true);
    const float dt = clock.restart().asSeconds();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        /*Update(dt);*/
        Render();

    }
  return 0;
}
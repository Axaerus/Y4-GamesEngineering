#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship*> ships;

sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "SFML works!");
sf::RectangleShape shape(sf::Vector2(800.f, 600.0f));

void Load() {
    //load method
    shape.setFillColor(Color::Black);

    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(IntRect(Vector2(0, 0), Vector2(32, 32)));

    Invader* inv = new Invader(sf::IntRect(Vector2(0, 0), Vector2(32, 32)), { 100,100 });
    ships.push_back(inv);
}

void Render() {
    //Render method
    window.clear();
    window.draw(shape);
    for (const auto s : ships) {
        window.draw(*s);
    }
    window.display();
}

void Update(float dt) {
    //Update method
    for (auto& s : ships) {
        s->Update(dt);
    };
}

int main(){

  Load();

  while (window.isOpen()){
      //Reset clock, recalculate deltatime
      static Clock clock;
      float dt = clock.restart().asSeconds();

      sf::Event event;
      while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
      }

      //Quit via ESC key
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
          window.close();
      }
      Update(dt);
      Render();
    /*window.clear();
    window.draw(shape2);
    window.draw(shape);
    window.display();*/
  }
  return 0;
}
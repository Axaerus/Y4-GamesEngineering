#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship*> ships;
Player* player;

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

    //Invader* inv = new Invader(sf::IntRect(Vector2(0, 0), Vector2(32, 32)), { 100,100 });
    //ships.push_back(inv);

    for (int r = 0; r < invaders_rows; ++r) {
        auto rect = IntRect(Vector2(0, 0), Vector2(32, 32));
        for (int c = 0; c < invaders_columns; ++c) {
            Vector2f position = Vector2f(226 + (32 * c), 100 + (32 * r));
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }
    player = new Player();
    ships.push_back(player);
}

void Render() {
    //Render method
    window.clear();
    window.draw(shape);
    for (const auto s : ships) {
        window.draw(*s);
    }
    Bullet::Render(window);
    window.display();
}

void Update(const float& dt) {
    //Update method
    for (auto& s : ships) {
        s->Update(dt);
    };
    Bullet::Update(dt);
}

int main(){
  static Clock clock;
  Load();

  while (window.isOpen()){
      //Reset clock, recalculate deltatime
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
  }
  return 0;
}
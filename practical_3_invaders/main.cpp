#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
sf::RectangleShape shape(sf::Vector2(800.f, 600.0f));


void Load() {
    //load method
    shape.setFillColor(Color::Black);

    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(IntRect(Vector2(0, 0), Vector2(32, 32)));
}

void Render() {
    //Render method
    window.clear();
    window.draw(shape);
    window.draw(invader);
    window.display();
}

void Update() {
    //Update method
}

int main(){

  Load();

  while (window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
      Render();
    /*window.clear();
    window.draw(shape2);
    window.draw(shape);
    window.display();*/
  }
  return 0;
}
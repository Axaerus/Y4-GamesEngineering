#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
  sf::CircleShape shape(100.f);
  sf::RectangleShape shape2(sf::Vector2(300.f, 300.0f));
  shape.setFillColor(sf::Color::Magenta);
  shape2.setFillColor(sf::Color::Green);
  shape.setPosition(sf::Vector2(50.f, 50.f));

  while (window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
    window.clear();
    window.draw(shape2);
    window.draw(shape);
    window.display();
  }
  return 0;
}
#include "ghost.h"

using namespace sf;
using namespace std;

Ghost::Ghost() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Red);
	_shape->setOrigin(Vector2f(25.f, 25.f));
}

void Ghost::Update(double dt) {
	Entity::Update(dt);
}

void Ghost::Render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}

Vector2f Ghost::getDimensions() {
	return _shape->getGlobalBounds().getSize();
}
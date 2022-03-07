#include "player.h"
using namespace sf;
using namespace std;

void Player::Update(double dt) {
    //Move in four directions based on 
    
    Vector2f direction = Vector2f(0,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        direction.x -= Player::_speed * dt;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        direction.x += Player::_speed * dt;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        direction.y -= Player::_speed * dt;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        direction.y += Player::_speed * dt;
    }
    move(direction);
    Entity::Update(dt);
}

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Yellow);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

Vector2f Player::getDimensions() {
    auto temp = _shape->getGlobalBounds();
    auto next = temp.getSize();
    return next;
}

void Player::Render(sf::RenderWindow& window) const {
    window.draw(*_shape);
}
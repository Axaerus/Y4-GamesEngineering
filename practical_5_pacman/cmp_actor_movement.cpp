#include "cmp_actor_movement.h"
#include <LevelSystem.h>

using namespace sf;

//Actor Movement Component Definitions
void ActorMovementComponent::update(double dt) {
    Component::update(dt);
}

ActorMovementComponent::ActorMovementComponent(Entity* p)
    : _speed(100.0f), Component(p) {}

//bool ActorMovementComponent::validMove(const sf::Vector2f& pos) {
//    return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
//}

void ActorMovementComponent::move(const sf::Vector2f& p) {
    auto pp = _parent->getPosition() + p;
    if (true/*validMove(pp)*/) {
        _parent->setPosition(pp);
    }
}

void ActorMovementComponent::move(float x, float y) {
    move(Vector2f(x, y));
}
float ActorMovementComponent::getSpeed() const {
    return _speed;
}

void ActorMovementComponent::setSpeed(float speed) {
    _speed = speed;
}

//Player Movement Component Definitions
PlayerMovementComponent::PlayerMovementComponent(Entity* p)
    : ActorMovementComponent(p) {}

void PlayerMovementComponent::update(double dt) {
    if (_parent->isAlive()) {
        Vector2f new_dir;
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            new_dir.y -= _speed * dt;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            new_dir.y += _speed * dt;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            new_dir.x -= _speed * dt;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            new_dir.x += _speed * dt;
        }
        move(new_dir);
    }
    ActorMovementComponent::update(dt);
}

// Enemy AI Movement Component Definitions
EnemyAIComponent::EnemyAIComponent(Entity* p)
    : ActorMovementComponent(p) {}

void EnemyAIComponent::update(double dt) {
    //todo: add code for AI
}

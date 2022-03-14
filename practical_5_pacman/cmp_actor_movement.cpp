#include "cmp_actor_movement.h"

using namespace sf;

//Actor Movement Component Definitions
void ActorMovementComponent::update(double dt) {
    Component::update(dt);
}

ActorMovementComponent::ActorMovementComponent(Entity* p)
    : _speed(100.0f), Component(p) {}

bool ActorMovementComponent::validMove(const sf::Vector2f& pos) {
    return (LevelSystem::getTileAt(pos) != LevelSystem::WALL);
}

void ActorMovementComponent::move(const sf::Vector2f& p) {
    auto pp = _parent->getPosition() + p;
    if (validMove(pp)) {
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
static const Vector2i directions[] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };

EnemyAIComponent::EnemyAIComponent(Entity* p)
    : ActorMovementComponent(p) {}

void EnemyAIComponent::update(double dt) {
    //amount to move
    const auto mva = (float)(dt * _speed);
    //Curent position
    const Vector2f pos = _parent->getPosition();
    //Next position
    const Vector2f newpos = pos + _direction * mva;
    //Inverse of our current direction
    const Vector2i baddir = -1 * Vector2i(_direction);
    //Random new direction
    Vector2i newdir = directions[(rand() % 4)];

    //FINISH STATES
    switch (_state) {
    case ROAMING:
        if (LevelSystem::getTileAt(newpos) == LevelSystem::WALL || LevelSystem::getTileAt(newpos) == LevelSystem::WAYPOINT)// Wall in front or at waypoint
        {
            // start rotate
        }
        else {
            //keep moving
        }
        break;

    case ROTATING:
        while (true
            // Don't reverse
            
            // and Don't pick a direction that will lead to a wall
            
            ) {
            // pick new direction
        }
        _direction = Vector2f(newdir);
        _state = ROTATED;
        break;

    case ROTATED:
        //have we left the waypoint?
        if (LevelSystem::getTileAt(pos) != LevelSystem::WAYPOINT) {
            _state = ROAMING; //yes
        }
        move(_direction * mva); //No
        break;
    }
    ActorMovementComponent::update(dt);
}

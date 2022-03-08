#include "ecm.h"

// Entity class declarations
Entity::Entity() {};

void Entity::render() {};

const sf::Vector2f& Entity::getPosition() const {
	return _position;
};

void Entity::setPosition(const sf::Vector2f& Position) {
	_position = Position;
};

bool Entity::is_fordeletion() const {
	return _fordeletion;
};

float Entity::getRotation() const {
	return _rotation;
};

void Entity::setRotation(float Rotation) {
	_rotation = Rotation;
};

bool Entity::isAlive() const {
	return _alive;
};

void Entity::setAlive(bool Alive) {
	_alive = Alive;
};

void Entity::setForDelete() {
	_fordeletion = true;
};

bool Entity::isVisible() const {
	return _visible;
};

void Entity::setVisible(bool IsVisible) {
	_visible = IsVisible;
};

// Component class declarations
Component::Component(Entity* const Parent) : _parent(Parent) {};

bool Component::is_fordeletion() const {
	return _fordeletion;
};

void Component::update(double dt) {};

void Component::render() {};
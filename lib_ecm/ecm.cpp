#include "ecm.h"

// Entity class declarations
Entity::Entity() : _components(std::vector<std::shared_ptr<Component>>()), _position(sf::Vector2f(0, 0)), 
_rotation(0), _alive(false), _visible(false), _fordeletion(false)
{};

void Entity::render() {};

void Entity::update(double dt) {};

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
Component::Component(Entity* const Parent) : _parent(Parent), _fordeletion(false) {};

bool Component::is_fordeletion() const {
	return _fordeletion;
};

void Component::update(double dt) {};

void Component::render() {};

Component::~Component() {
	
};
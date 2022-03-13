#if 0
#include "entity.h"
#include "system_renderer.h"
using namespace std;
using namespace sf;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f& pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position += pos; }

void Entity::Update(const double dt) {
    _shape->setPosition(_position);
}

Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}

void EntityManager::update(double dt) {
    for (auto item : list) {
        item->Update(dt);
    }
}

void EntityManager::render() {
    for (auto item : list) {
        //item->Render(window);
        Renderer::queue(item->getShape());
    }
}
#endif // 0

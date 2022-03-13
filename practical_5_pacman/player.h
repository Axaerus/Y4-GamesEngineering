#pragma once
#include "ecm.h"
#include "cmp_sprite.h"

class Player : public Entity {
private:
	float _speed;

public:
	void update(double dt) override;
	Player();
	void render() override;
	sf::Vector2f getDimensions();
};
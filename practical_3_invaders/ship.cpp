#include "ship.h"
#include "game.h"
#include "bullet.h"
using namespace sf;
using namespace std;

// --- Ship Abstract class ---
Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::BoundaryShift() {}

void Ship::Update(const float& dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;


// --- Invader class ---
Invader::Invader() : Ship() {}

bool Invader::direction;
float Invader::speed = 75;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(Vector2f(16.f, 16.f));;
	setPosition(pos);
}

void Invader::BoundaryShift() {
	move(Vector2f(0.0f, 24.0f));
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);

	move(Vector2f(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f));

	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size(); i++) {
			ships[i]->BoundaryShift();
		}
	}
}



// --- Player Class ---
Player::Player() : Ship(IntRect(Vector2(160, 32), Vector2(32, 32))) {
	setPosition({ gameWidth * .5f, gameHeight - 32.f });
}

float Player::speed = 175;

void Player::Update(const float& dt) {
	Ship::Update(dt);
	
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		move(Vector2f(-speed * dt, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		move(Vector2f(speed * dt, 0));
	}

	static vector<Bullet*> bullets;
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		bullets.push_back(new Bullet(getPosition(), false));
	}
	for (const auto s : bullets) {
		s->Update(dt);
	}
}


#include "bullet.h"
#include "game.h"
using namespace sf;
using namespace std;

Bullet::Bullet() = default;

bool _mode = false;
Bullet Bullet::bullets[256];
unsigned char Bullet::bulletPointer;

Bullet::Bullet(const sf::Vector2f& pos, const bool mode) {
    setTexture(spritesheet);
    setTextureRect(IntRect(Vector2(32, 32), Vector2(64, 64)));
	setPosition(pos);
	_mode = mode;
};

void Bullet::Update(const float& dt) {
    for (int i = 0; i < sizeof(bullets) / sizeof(*bullets); i++) {
        bullets[i]._Update(dt);
    }
};

void Bullet::Render(sf::RenderWindow& window) {
    //Render method
    for (auto const b : bullets)
    {
        window.draw(b);
    }
};

void Bullet::Fire(const sf::Vector2f& pos, const bool mode) {
    //Fire method
   bullets[++bulletPointer].setPosition(pos);
   bullets[++bulletPointer]._mode = mode;
};

void Bullet::Init() {
    //Init method
    for (int i = 0; i < sizeof(bullets) / sizeof(*bullets); i++) {
        bullets[i] = Bullet::Bullet(Vector2f(-100, -100), false);
    }
};

void Bullet::_Update(const float& dt) {
    if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
        //off screen - do nothing
        return;
    }
    else {
        move(Vector2f(0, dt * 200.0f * (_mode ? 1.0f : -1.0f)));
        const FloatRect boundingBox = getGlobalBounds();

        for (auto s : ships) {
            if (!_mode && s == player) {
                //player bulelts don't collide with player
                continue;
            }
            if (_mode && s != player) {
                //invader bullets don't collide with other invaders
                continue;
            }
            if (!s->is_exploded() &&
                s->getGlobalBounds().intersects(boundingBox)) {
                //Explode the ship
                s->Explode();
                //warp bullet off-screen
                setPosition(Vector2f(-100, -100));
                return;
            }
        }
    }
};
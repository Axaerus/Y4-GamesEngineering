#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	void Update(const float& dt);
	explicit Bullet(const sf::Vector2f& pos, const bool mode);
	~Bullet() = default;
protected:
	static unsigned char bulletPointer;
	static Bullet bullets[256];
	void _Update(const float& dt);
	Bullet();
	//false=player bullet, true=Enemy bullet
	bool _mode;
};

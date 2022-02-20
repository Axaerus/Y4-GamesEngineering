#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    //Default constructor is hidden
    Ship();
    bool _exploded = false;
public:
    //Constructor that takes a sprite
    explicit Ship(sf::IntRect ir);
    //Pure virtual deconstructor -- makes this an abstract class and avoids undefined behaviour!
    virtual ~Ship() = 0;
    //Shifts ship down on boundary collision
    virtual void BoundaryShift();
    //Update, virtual so can be overridden, but not pure virtual
    virtual void Update(const float& dt);
    //Check if is exploded
    bool is_exploded() const;
    //Explodes ship
    virtual void Explode();
};

class Invader : public Ship {
public:
    static bool direction;
    static float speed;

    Invader(sf::IntRect ir, sf::Vector2f pos);
    Invader();
    void Update(const float& dt) override;
    void BoundaryShift() override;
};

class Player : public Ship {
public:
    static float speed;

    Player();
    void Update(const float& dt) override;
};
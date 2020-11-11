#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"
class Enemy
{
public:

    Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Enemy();
    void update(float deltaTime);
    void update1(float deltaTime);
    void draw(sf::RenderWindow& window);
    Collision GetCollider() { return Collision(body); }

private:
    int row;
    bool faceRight;
    sf::RectangleShape body;
    Animation animation;
    float posx;
    float posy;
    float face;
    sf::Vector2f Velocity;
};

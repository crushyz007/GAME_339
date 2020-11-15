#include "Pokemon.h"
#include<iostream>

Pokemon::Pokemon(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    countBullet = 0;
    body.setSize(sf::Vector2f(45.0f, 63.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}
Pokemon::~Pokemon()
{
}
void Pokemon::update(float deltaTime, Bulletpoke BulleT) {
    animation.UpdateBullet(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    if (BulleT.GetCollider().CheckCollision(this->GetCollider()))
    {
        countBullet++;
        body.setPosition(-1000.0f, 350.0f);
    }
}
void Pokemon::draw(sf::RenderWindow& window) {
    window.draw(body);
}
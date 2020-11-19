#include "Pokemon.h"
#include<iostream>

Pokemon::Pokemon(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    this->posx = x;
    this->posy = y;
    this->face = 1;
    this->countBullet = 0;
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}
Pokemon::~Pokemon()
{
}
void Pokemon::update(float deltaTime, Bulletpoke BulleT)
{
    animation.UpdateBullet(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.setSize(sf::Vector2f(54.0f, 64.0f));

    if (BulleT.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->countBullet++;
        body.setPosition(-1000.0f, 350.0f);
    }
}
void Pokemon::update1(float deltaTime, Bulletpoke BulleT)
{

    float posyy = body.getPosition().y;
    velocity.y = 80.0f;
    velocity.x = 0.0f;
    body.setSize(sf::Vector2f(45.0f, 55.0f));
    if (posyy > this->posy + 200) {
        this->face = -1;
        row = 1;
    }
    else if (posyy < this->posy) {
        this->face = 1;
        row = 0;
    }
    body.move(this->face * velocity * deltaTime);

    animation.UpdateBullet(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    if (BulleT.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->countBullet++;
        body.setPosition(-1000.0f, 350.0f);
    }
}
void Pokemon::update2(float deltaTime, Bulletpoke BulleT)
{
    float posxx = body.getPosition().x;
    velocity.x = 100.0f;
    velocity.y = 0.0f;
    body.setSize(sf::Vector2f(45.0f, 63.0f));
    if (posxx > this->posx + 200) {
        this->face = -1;
        row = 0;
    }
    else if (posxx < this->posx) {
        this->face = 1;
        row = 1;
    }
    body.move(this->face * velocity * deltaTime);

    animation.UpdateBullet(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (BulleT.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->countBullet++;
        body.setPosition(-1000.0f, 350.0f);
    }
}
void Pokemon::draw(sf::RenderWindow& window) {
    window.draw(body);
}
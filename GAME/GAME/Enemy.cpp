#include "Enemy.h"
#include<iostream>
Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    row = 0;
    this->posx = x;
    this->posy = y;
    this->face = 1;
    body.setSize(sf::Vector2f(45.0f, 54.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(this->posx, this->posy);
    body.setTexture(texture);
}

Enemy::~Enemy()
{

}
void Enemy::update(float deltaTime)
{
    float posxx = body.getPosition().x;
    Velocity.x = 100.0f;
    Velocity.y = 0.0f;
    if (posxx > this->posx + 200) {
        this->face = -1;
    }
    else if (posxx < this->posx) {
        this->face = 1;
    }
    body.move(this->face * Velocity * deltaTime);
    animation.UpdateItem(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);

}

void Enemy::update1(float deltaTime)
{
    float posyy = body.getPosition().y;
    Velocity.y = 80.0f;
    Velocity.x = 0.0f;
    if (posyy > this->posy + 200) {
        this->face = -1;
    }
    else if (posyy < this->posy) {
        this->face = 1;
    }
    body.move(this->face * Velocity * deltaTime);
    animation.UpdateItem(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);

}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(body);
}
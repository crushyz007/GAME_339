#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Bulletpoke
{
public:
    Bulletpoke(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos);
    ~Bulletpoke();
    void updateUP(float deltaTime);
    void updateDOWN(float deltaTime);
    void updateRIGHT(float deltaTime);
    void updateLEFT(float deltaTime);
    void attackL(sf::Vector2f pos);
    void attackR(sf::Vector2f pos);
    void attackU(sf::Vector2f pos);
    void attackD(sf::Vector2f pos);
    void draw(sf::RenderWindow& window);
    void deletepoke();

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collision GetCollider() { return Collision(body); }

private:
    int faceD;
    Animation animation;
    float speed;
    sf::RectangleShape body;
    unsigned int row;
    sf::Vector2f velocity;
};
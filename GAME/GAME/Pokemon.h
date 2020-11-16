#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include"Bulletpoke.h"
#include"Collision.h"

class Pokemon
{
public:
	Pokemon(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
	~Pokemon();
	void update(float deltaTime, Bulletpoke BulleT);
	void update1(float deltaTime, Bulletpoke BulleT);
	void update2(float deltaTime, Bulletpoke BulleT);
	void draw(sf::RenderWindow& window);
	Collision GetCollider() { return Collision(body); }

	int isBul()
	{
		if (this->countBullet == 1) {
			this->countBullet--;
			return 1;
		}
	}

private:
	int row;
	int countBullet;
	float speed;
	sf::RectangleShape body;
	Animation animation;
	sf::Vector2f velocity;
	float posx;
	float posy;
	float face;
};


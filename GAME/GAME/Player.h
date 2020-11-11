#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include"Collision.h"
#include"Enemy.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void Setposition(float x, float y);
	void UpdateEnemy(float deltaTime, std::vector<Enemy>& EnemyVector);
	void UpdateEnemy1(float deltaTime, std::vector<Enemy>& EnemyVector1);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollision() { return Collision(body); }

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	bool faceTop;

};

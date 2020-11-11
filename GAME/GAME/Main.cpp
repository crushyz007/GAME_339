#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Animation.h"
#include"Platform.h"
#include"Collision.h"
#include"Item.h"
#include"Enemy.h"

//static const float VIEW_HEIGHT = 1080.0f;
//static const float VIEW_WIDE = 720.0f;

/*void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
	view.setSize(VIEW_WIDE * aspectRatio, VIEW_WIDE);
}*/
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SATOSHI!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080, 720));

	//ash
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/ash1.png");
	sf::Sprite playerSprite;
	//playerSprite.scale(4.0f, 4.0f);

	Player player(&playerTexture, sf::Vector2u(5, 4), 0.4f, 180.0f);

	//map1
	sf::RectangleShape bg(sf::Vector2f(2280.0f, 1920.0f));
	sf::Texture background;
	bg.setPosition(0.0f, 0.0f);
	background.loadFromFile("texture/map22.png");
	bg.setTexture(&background);

	//map2
	sf::RectangleShape bg2(sf::Vector2f(2280.0f, 1920.0f));
	sf::Texture background2;
	background2.loadFromFile("texture/map333.png");
	bg2.setPosition(2300.0f, 0.0f);
	bg2.setTexture(&background2);

	//map3
	sf::RectangleShape bg3(sf::Vector2f(2280.0f, 1920.0f));
	sf::Texture background3;
	background3.loadFromFile("texture/map11.png");
	bg3.setPosition(2300.0f, 2100.0f);
	bg3.setTexture(&background3);

	//time
	float deltaTime = 0.0f; //delay
	sf::Clock clock;

	int animationFrame = 0;

	//Platform
	Collision playerCollision = player.GetCollision(); // (w,l)block,(w,l)move,address
	Platform platform1(nullptr, sf::Vector2f(20.0f, 1920.0f), sf::Vector2f(-20.0f, 960.0f)); //left
	Platform platform2(nullptr, sf::Vector2f(2280.0f, 20.0f), sf::Vector2f(1140.0f, -20.0f));//top
	Platform platform3(nullptr, sf::Vector2f(2280.0f, 20.0f), sf::Vector2f(1140.0f, 1915.0f));//down
	Platform platform4(nullptr, sf::Vector2f(20.0f, 1920.0f), sf::Vector2f(2300.0f, 960.0f));//right
	Platform platform5(nullptr, sf::Vector2f(2280.0f, 207.0f), sf::Vector2f(1113.0f, 87.0f));
	Platform platform6(nullptr, sf::Vector2f(92.0f, 500.0f), sf::Vector2f(24.0f, 502.0f));
	Platform platform7(nullptr, sf::Vector2f(660.0f, 160.0f), sf::Vector2f(572.0f, 375.0f));
	Platform platform8(nullptr, sf::Vector2f(160.0f, 130.0f), sf::Vector2f(520.0f, 620.0f));
	Platform platform9(nullptr, sf::Vector2f(390.0f, 212.0f), sf::Vector2f(595.0f, 920.0f));
	Platform platform10(nullptr, sf::Vector2f(269.0f, 150.0f), sf::Vector2f(1400.0f, 650.0f));
	Platform platform11(nullptr, sf::Vector2f(570.0f, 160.0f), sf::Vector2f(1780.0f, 372.0f));
	Platform platform12(nullptr, sf::Vector2f(1142.0f, 242.0f), sf::Vector2f(789.0f, 1346.0f));
	Platform platform13(nullptr, sf::Vector2f(539.0f, 395.0f), sf::Vector2f(1769.0f, 1274.0f));
	Platform platform14(nullptr, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(1821.0f, 1808.0f));
	Platform platform15(nullptr, sf::Vector2f(81.0f, 913.0f), sf::Vector2f(28.0f, 1464.0f));
	Platform platform16(nullptr, sf::Vector2f(297.0f, 248.0f), sf::Vector2f(725.0f, 1783.0f));
	Platform platform17(nullptr, sf::Vector2f(464.0f, 130.0f), sf::Vector2f(318.0f, 1828.0f));
	Platform platform18(nullptr, sf::Vector2f(50.0f, 751.0f), sf::Vector2f(2231.0f, 325.0f));
	Platform platform19(nullptr, sf::Vector2f(80.0f, 736.0f), sf::Vector2f(2203.0f, 1470.0f));
	Platform platform20(nullptr, sf::Vector2f(449.0f, 1.0f), sf::Vector2f(840.0f, 590.0f));
	Platform platform21(nullptr, sf::Vector2f(340.0f, 1.0f), sf::Vector2f(1291.0f, 450.0f));
	Platform platform22(nullptr, sf::Vector2f(3.0f, 7.0f), sf::Vector2f(1070.0f, 520.0f));
	Platform platform23(nullptr, sf::Vector2f(650.0f, 1.0f), sf::Vector2f(1851.0f, 880.0f));
	/*Platform platform24(nullptr, sf::Vector2f(420.0f, 20.0f), sf::Vector2f(1020.0f, 1048.0f));
	Platform platform25(nullptr, sf::Vector2f(255.0f,34.0f), sf::Vector2f(218.0f, 813.0f));
	Platform platform26(nullptr, sf::Vector2f(390.0f, 202.0f), sf::Vector2f(1781.0f, 660.0f));
	Platform platform27(nullptr, sf::Vector2f(18.0f, 207.0f), sf::Vector2f(340.0f, 937.0f));
	Platform platform28(nullptr, sf::Vector2f(18.0f, 321.0f), sf::Vector2f(1223.0f, 860.0f));
	Platform platform29(nullptr, sf::Vector2f(234.0f, 28.0f), sf::Vector2f(1591.0f, 1564.0f));
	Platform platform30(nullptr, sf::Vector2f(186.0f, 28.0f), sf::Vector2f(1948.0f, 1565.0f));*/

	//pokeball 
	sf::Texture ITEM;
	ITEM.loadFromFile("texture/pokebon.png");
	std::vector <Item> itemVector;
	//itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 400.0f, 530.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 500.0f, 530.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 600.0f, 530.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 700.0f, 530.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 790.0f, 530.0f));
	//itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 790.0f, 450.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 790.0f, 380.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1663.0f, 619.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1200.0f, 500.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1800.0f, 500.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1800.0f, 800.0f));

	//point
	int countpoint = 0;

	//state pokemon
	//pokeball 0
	sf::Texture poke0;
	poke0.loadFromFile("texture/p0.png");
	sf::RectangleShape statepoke(sf::Vector2f(200, 100));
	statepoke.setPosition(sf::Vector2f(view.getCenter().x + 10, 520));
	statepoke.setTexture(&poke0);

	//pokeball 1
	sf::Texture poke1;
	poke1.loadFromFile("texture/p1.png");
	sf::RectangleShape statepoke1(sf::Vector2f(200, 100));
	statepoke1.setPosition(sf::Vector2f(0, 0));
	statepoke1.setTexture(&poke1);

	//pokeball 2
	sf::Texture poke2;
	poke2.loadFromFile("texture/p2.png");
	sf::RectangleShape statepoke2(sf::Vector2f(200, 100));
	statepoke2.setPosition(sf::Vector2f(0, 0));
	statepoke2.setTexture(&poke2);

	//pokeball 3
	sf::Texture poke3;
	poke3.loadFromFile("texture/p3.png");
	sf::RectangleShape statepoke3(sf::Vector2f(200, 100));
	statepoke3.setPosition(sf::Vector2f(0, 0));
	statepoke3.setTexture(&poke3);

	//pokeball 4
	sf::Texture poke4;
	poke4.loadFromFile("texture/p4.png");
	sf::RectangleShape statepoke4(sf::Vector2f(200, 100));
	statepoke4.setPosition(sf::Vector2f(0, 0));
	statepoke4.setTexture(&poke4);

	//pokeball 5
	sf::Texture poke5;
	poke5.loadFromFile("texture/p5.png");
	sf::RectangleShape statepoke5(sf::Vector2f(200, 100));
	statepoke5.setPosition(sf::Vector2f(0, 0));
	statepoke5.setTexture(&poke5);

	sf::Font font;
	font.loadFromFile("texture/ABCD.ttf");
	std::ostringstream point;
	sf::Text Score;
	Score.setCharacterSize(30);
	Score.setString(point.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::White);

	//Enemy
	sf::Texture ENEMY;
	sf::Texture ENEMY1;
	ENEMY.loadFromFile("texture/enemy.png");
	ENEMY1.loadFromFile("texture/cointest.png");
	std::vector <Enemy> EnemyVector;
	std::vector <Enemy> EnemyVector1;
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(6, 1), 0.08f, 400.0f, 530.0f));
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(6, 1), 0.08f, 200.0f, 530.0f));
	int u = 0;
	while (window.isOpen())
	{

		int count = player.GetPosition().x;

		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//ResizeView(window, view);
				break;
			case sf::Event::TextEntered:
				break;
			}
		}

		player.Update(deltaTime);
		view.setCenter(player.GetPosition());
		if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(540.0f, 360.0f);//window
			}
			if (view.getCenter().y + 360.0f >= 1920.0f)
			{
				view.setCenter(540.0f, 1560.0f);//window
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1920.0f)
			{
				view.setCenter(540.0f, player.GetPosition().y);
			}

		}
		if (view.getCenter().x + 540.0f >= 2280.0f) //between lawang lao
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(1740.0f, 360.0f);
			}
			if (view.getCenter().y + 360.0f >= 1920.0f)
			{
				view.setCenter(1740.0f, 1560.0f);
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1920.0f)
			{
				view.setCenter(1740.0f, player.GetPosition().y);
			}
		}
		if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 2280.0f) //up down mid nidnoi
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(player.GetPosition().x, 360.0f);
			}
			if (view.getCenter().y + 360.0f >= 1920.0f)
			{
				view.setCenter(player.GetPosition().x, 1560.0f);
			}
		}

		//warp to map2
		if ((player.GetPosition().x >= 2000 && player.GetPosition().x <= 2240) && (player.GetPosition().y >= 930 && player.GetPosition().y <= 1000)) {
			u = 1;
			player.Setposition(2740, 980);
		}
		if (u == 1)
		{
			view.setCenter(player.GetPosition());
			if (view.getCenter().x - 540.0f <= 2300.0f)//left
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(2840.0f, 360.0f);//window
				}
				if (view.getCenter().y + 360.0f >= 1920.0f)
				{
					view.setCenter(2840.0f, 1560.0f);//window
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1920.0f)
				{
					view.setCenter(2840.0f, player.GetPosition().y);
				}

			}
			if (view.getCenter().x + 540.0f >= 4580.0f) //right
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(4040.0f, 360.0f);
				}
				if (view.getCenter().y + 360.0f >= 1920.0f)
				{
					view.setCenter(4040.0f, 1560.0f);
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1920.0f)
				{
					view.setCenter(4040.0f, player.GetPosition().y);
				}
			}
			if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 4580.0f) //down
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(player.GetPosition().x, 360.0f);
				}
				if (view.getCenter().y + 360.0f >= 1920.0f)
				{
					view.setCenter(player.GetPosition().x, 1560.0f);
				}
			}
		}
		//warp to map3
		if ((player.GetPosition().x >= 3500 && player.GetPosition().x <= 3550) && (player.GetPosition().y >= 1750 && player.GetPosition().y <= 1830)) {
			u = 2;
			player.Setposition(3431, 2383);
		}
		if (u == 2)
		{
			view.setCenter(player.GetPosition());
			if (view.getCenter().x - 540.0f <= 2305.0f)//left
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(2845.0f, 360.0f);//window
				}
				if (view.getCenter().y + 360.0f >= 3840.0f)
				{
					view.setCenter(2845.0f, 3480.0f);//window
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 3840.0f)
				{
					view.setCenter(2845.0f, player.GetPosition().y);
				}

			}
			if (view.getCenter().x + 540.0f >= 4580.0f) //right
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(4040.0f, 360.0f);
				}
				if (view.getCenter().y + 360.0f >= 3840.0f)
				{
					view.setCenter(4040.0f, 3480.0f);
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 3840.0f)
				{
					view.setCenter(4040.0f, player.GetPosition().y);
				}
			}
			if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 4580.0f) //down
			{
				if (view.getCenter().y - 360.0f <= 2098.0f)
				{
					view.setCenter(player.GetPosition().x, 2460.0f);
				}
				if (view.getCenter().y + 360.0f >= 3840.0f)
				{
					view.setCenter(player.GetPosition().x, 3480.0f);
				}
			}
		}

		//PlatformDraw
		platform1.Draw(window);
		platform2.Draw(window);
		platform3.Draw(window);
		platform4.Draw(window);
		platform5.Draw(window);
		platform6.Draw(window);
		platform7.Draw(window);
		platform8.Draw(window);
		platform9.Draw(window);
		platform10.Draw(window);
		platform11.Draw(window);
		platform12.Draw(window);
		platform13.Draw(window);
		platform14.Draw(window);
		platform15.Draw(window);
		platform16.Draw(window);
		platform17.Draw(window);
		platform18.Draw(window);
		platform19.Draw(window);
		platform20.Draw(window);
		platform21.Draw(window);
		platform22.Draw(window);
		platform23.Draw(window);
		/*//platform24.Draw(window);
		platform25.Draw(window);
		//platform26.Draw(window);
		platform27.Draw(window);
		platform28.Draw(window);
		platform29.Draw(window);
		platform30.Draw(window);*/

		//pokeview
		if (pos.x > 210) {
			statepoke.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke1.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke2.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke3.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke4.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke5.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
		}

		//point
		point.str(" ");
		point << "pokeball :  " << countpoint;
		Score.setString(point.str());
		Score.setPosition({ view.getCenter().x - 300 ,view.getCenter().y - 335 });
		for (int i = 0; i < itemVector.size(); i++) {
			if (itemVector[i].iscollide() == 1)
			{
				countpoint += 1;
			}
		}

		//Update Item
		for (int i = 0; i < itemVector.size(); i++)
		{
			itemVector[i].update(deltaTime, player);
		}
		//Update Enemy
		for (int i = 0; i < EnemyVector.size(); i++)
		{
			EnemyVector[i].update(deltaTime);
		}
		for (int i = 0; i < EnemyVector1.size(); i++)
		{
			EnemyVector1[i].update1(deltaTime);
		}


		window.clear();
		window.setView(view);
		window.draw(bg);
		window.draw(bg2);
		window.draw(bg3);

		//Draw Item
		for (int i = 0; i < itemVector.size(); i++)
		{
			itemVector[i].draw(window);
		}
		//Draw Enemy
		for (int i = 0; i < EnemyVector.size(); i++)
		{
			EnemyVector[i].draw(window);
		}
		for (int i = 0; i < EnemyVector1.size(); i++)
		{
			EnemyVector1[i].draw(window);
		}
		player.UpdateEnemy1(deltaTime, EnemyVector1);
		player.UpdateEnemy(deltaTime, EnemyVector);
		player.Draw(window);

		//pokestate
		window.draw(statepoke);
		if (countpoint == 1)window.draw(statepoke1);
		else if (countpoint == 2)window.draw(statepoke2);
		else if (countpoint == 3)window.draw(statepoke3);
		else if (countpoint == 4)window.draw(statepoke4);
		else if (countpoint == 5)window.draw(statepoke5);
		else if (countpoint == 6)window.draw(statepoke5);
		else if (countpoint == 7)window.draw(statepoke5);
		else if (countpoint == 8)window.draw(statepoke5);
		else if (countpoint == 9)window.draw(statepoke5);
		else if (countpoint == 10)window.draw(statepoke5);
		else if (countpoint == 11)window.draw(statepoke5);
		else if (countpoint == 12)window.draw(statepoke5);
		else if (countpoint == 13)window.draw(statepoke5);
		else if (countpoint == 14)window.draw(statepoke5);
		else if (countpoint == 15)window.draw(statepoke5);

		window.draw(Score);
		window.display();

		//CheckCollision
		platform1.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform2.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform3.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform4.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform5.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform6.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform7.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform8.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform9.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform10.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform11.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform12.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform13.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform14.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform15.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform16.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform17.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform18.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform19.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform20.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform21.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform22.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform23.GetCollision().CheckCollision(playerCollision, 1.0f);
		/*platform24.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform25.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform26.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform27.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform28.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform29.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform30.GetCollision().CheckCollision(playerCollision, 1.0f);*/

	}
	return 0;
}
//hello
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
	sf::RectangleShape bg2(sf::Vector2f(1800.0f, 1650.0f));
	sf::Texture background2;
	background2.loadFromFile("texture/map11.png");
	bg2.setPosition(1850.0f, 0.0f);
	bg2.setTexture(&background2);

	/*//map2test
	sf::RectangleShape bg2(sf::Vector2f(2850.0f, 954.0f));
	sf::Texture background2;
	bg2.setPosition(4500.0f, 0.0f);
	background2.loadFromFile("texture/map2test.png");
	bg2.setTexture(&background2);

	//map2test2
	sf::RectangleShape bg3(sf::Vector2f(2850.0f, 954.0f));
	sf::Texture background3;
	bg3.setPosition(4500.0f, 1000.0f);
	background3.loadFromFile("texture/map2test2.png");
	bg3.setTexture(&background3);*/


	//time
	float deltaTime = 0.0f; //delay
	sf::Clock clock;

	int animationFrame = 0;

	/*//Platform
	Collision playerCollision = player.GetCollision(); // (w,l)block,(w,l)move,address
	Platform platform1(nullptr, sf::Vector2f(20.0f, 954.0f), sf::Vector2f(-20.0f, 477.0f)); //left
	Platform platform2(nullptr, sf::Vector2f(2850.0f, 20.0f), sf::Vector2f(1425.0f, -20.0f));//top
	Platform platform3(nullptr, sf::Vector2f(2850.0f, 20.0f), sf::Vector2f(1425.0f, 950.0f));//down
	Platform platform4(nullptr, sf::Vector2f(20.0f, 954.0f), sf::Vector2f(2870, 477.0f));//right
	//Platform platform5(nullptr, sf::Vector2f(1300.0f, 400.0f), sf::Vector2f(40.0f, 150.0f));//block1top
	Platform platform5(nullptr, sf::Vector2f(1300.0f, 600.0f), sf::Vector2f(40.0f, 55.0f));//block1top
	Platform platform6(nullptr, sf::Vector2f(1500.0f, 400.0f), sf::Vector2f(450.0f, 850.0f));//block2down
	Platform platform7(nullptr, sf::Vector2f(2600.0f, 200.0f), sf::Vector2f(2800.0f, 150.0f));//mountain++
	Platform platform8(nullptr, sf::Vector2f(400.0f, 350.0f), sf::Vector2f(1300.0f, 850.0f));//river1down
	Platform platform9(nullptr, sf::Vector2f(480.0f, 5.0f), sf::Vector2f(2020.0f, 880.0f));//forest down
	Platform platform10(nullptr, sf::Vector2f(690.0f, 300.0f), sf::Vector2f(1400.0f, 50.0f));//riverup1
	//Platform platform11(nullptr, sf::Vector2f(230.0f, 500.0f), sf::Vector2f(1800.0f, 50.0f));//riverup2*/

	//Star
	sf::Texture ITEM;
	ITEM.loadFromFile("texture/pokebon.png");
	std::vector <Item> itemVector;
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 400.0f, 530.0f));
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
		if (view.getCenter().x + 540.0f >= 2280.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(1770.0f, 360.0f);//window 1248-540 collision right 
			}
			if (view.getCenter().y + 360.0f >= 1920.0f)
			{
				view.setCenter(1770.0f, 1560.0f);//window 1248-540
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1920.0f)
			{
				view.setCenter(1770.0f, player.GetPosition().y);
			}
		}
		if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 2280.0f)
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


		/*//PlatformDraw
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
		//platform11.Draw(window);


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
		//platform11.GetCollision().CheckCollision(playerCollision, 1.0f);*/

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
		for (int i = 0; i < itemVector.size(); i++)
		{
			itemVector[i].update(deltaTime, player);
		}

		//warp to map2
		/*if ((player.GetPosition().x >= 1939 && player.GetPosition().x <= 2112) && (player.GetPosition().y >= 619 && player.GetPosition().y <= 639)) {
			std::cout << "...........................";
			player.Setposition(4500, 1500);
		}*/

		window.clear();
		window.setView(view);
		window.draw(bg);
		//window.draw(bg2);
		//window.draw(bg3);

		for (int i = 0; i < itemVector.size(); i++)
		{
			itemVector[i].draw(window);
		}
		//window.draw(collision2);

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

	}
	return 0;
}
//hello
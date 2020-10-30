#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include"Platform.h"

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

	//bg
	sf::RectangleShape bg(sf::Vector2f(2850.0f, 954.0f));
	sf::Texture background;
	background.loadFromFile("texture/map1.png");
	bg.setTexture(&background);

	//time
	float deltaTime = 0.0f; //delay‡«≈“
	sf::Clock clock;

	int animationFrame = 0;
	
	//Platform
	Collision playerCollision = player.GetCollision();
	Platform platform1(nullptr, sf::Vector2f(20.0f, 954.0f), sf::Vector2f(-20.0f, 477.0f)); //left
	Platform platform2(nullptr, sf::Vector2f(2850.0f, 20.0f), sf::Vector2f(1425.0f, -20.0f));//top
	Platform platform3(nullptr, sf::Vector2f(2850.0f, 20.0f), sf::Vector2f(1425.0f, 950.0f));//down
	Platform platform4(nullptr, sf::Vector2f(20.0f, 954.0f), sf::Vector2f(2870, 477.0f));//right

	while (window.isOpen())
	{
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
			if (view.getCenter().y + 360.0f >= 954.0f)
			{
				view.setCenter(540.0f, 594.0f);//window
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 954.0f)
			{
				view.setCenter(540.0f, player.GetPosition().y);
			}

		}
		if (view.getCenter().x + 540.0f >= 2850.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(2310.0f, 360.0f);//window 1248-540 collision right 
			}
			if (view.getCenter().y + 360.0f >= 954.0f)
			{
				view.setCenter(2310.0f, 594.0f);//window 1248-540
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 954.0f)
			{
				view.setCenter(2310.0f, player.GetPosition().y);
			}
		}
		if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 2850.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(player.GetPosition().x, 360.0f);
			}
			if (view.getCenter().y + 360.0f >= 954.0f)
			{
				view.setCenter(player.GetPosition().x, 594.0f);
			}
		}
		//PlatformDraw
		platform1.Draw(window);
		platform2.Draw(window);
		platform3.Draw(window);
		platform4.Draw(window);

		//CheckCollision
		platform1.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform2.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform3.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform4.GetCollision().CheckCollision(playerCollision, 1.0f);

		window.clear();
		window.setView(view);
		window.draw(bg);
		//window.draw(collision2);
		player.Draw(window);
		window.display();

	}
	return 0;
}
//hello
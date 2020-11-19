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
#include"Bulletpoke.h"
#include"Pokemon.h"

int bulletDirection;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SATOSHI!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080, 720));

	//ash
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture/ash1.png");
	sf::Sprite playerSprite;
	//playerSprite.scale(4.0f, 4.0f);

	Player player(&playerTexture, sf::Vector2u(5, 4), 0.2f, 180.0f);

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

	//sound main game
	sf::Music music;
	music.openFromFile("texture/PaletteTown1.wav");
	music.setVolume(10.0f);
	music.play();

	//sound taking a pokeball
	sf::SoundBuffer sound;
	sound.loadFromFile("texture/Caught1.wav");
	sf::Sound soundTake;
	soundTake.setBuffer(sound);
	soundTake.setVolume(100.0f);

	//sound taking a pokemon
	sf::SoundBuffer sound1;
	sound1.loadFromFile("texture/Taking.wav");
	sf::Sound soundKeep;
	soundKeep.setBuffer(sound1);
	soundKeep.setVolume(100.0f);

	//time
	float deltaTime = 0.0f; //delay
	sf::Clock clock;

	int animationFrame = 0;

	//Platform
	Collision playerCollision = player.GetCollision(); // (w,l)block,(w,l)move,address
	//map1
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
	Platform platform13(nullptr, sf::Vector2f(539.0f, 360.0f), sf::Vector2f(1769.0f, 1274.0f));
	Platform platform14(nullptr, sf::Vector2f(800.0f, 200.0f), sf::Vector2f(1821.0f, 1808.0f));
	Platform platform15(nullptr, sf::Vector2f(81.0f, 913.0f), sf::Vector2f(28.0f, 1464.0f));
	Platform platform16(nullptr, sf::Vector2f(297.0f, 248.0f), sf::Vector2f(725.0f, 1783.0f));
	Platform platform17(nullptr, sf::Vector2f(464.0f, 130.0f), sf::Vector2f(318.0f, 1828.0f));
	Platform platform18(nullptr, sf::Vector2f(50.0f, 980.0f), sf::Vector2f(2231.0f, 325.0f));
	Platform platform19(nullptr, sf::Vector2f(80.0f, 736.0f), sf::Vector2f(2203.0f, 1470.0f));
	Platform platform20(nullptr, sf::Vector2f(449.0f, 1.0f), sf::Vector2f(840.0f, 590.0f));
	Platform platform21(nullptr, sf::Vector2f(340.0f, 1.0f), sf::Vector2f(1291.0f, 450.0f));
	Platform platform22(nullptr, sf::Vector2f(3.0f, 7.0f), sf::Vector2f(1070.0f, 520.0f));
	Platform platform23(nullptr, sf::Vector2f(650.0f, 1.0f), sf::Vector2f(1851.0f, 880.0f));
	Platform platform24(nullptr, sf::Vector2f(350.0f, 3.0f), sf::Vector2f(1030.0f, 1030.0f));
	Platform platform25(nullptr, sf::Vector2f(255.0f, 4.0f), sf::Vector2f(218.0f, 800.0f));
	Platform platform26(nullptr, sf::Vector2f(380.0f, 150.0f), sf::Vector2f(1781.0f, 640.0f));
	Platform platform27(nullptr, sf::Vector2f(3.0f, 190.0f), sf::Vector2f(360.0f, 937.0f));
	Platform platform28(nullptr, sf::Vector2f(1.0f, 321.0f), sf::Vector2f(1223.0f, 860.0f));
	Platform platform29(nullptr, sf::Vector2f(180.0f, 0.5f), sf::Vector2f(1591.0f, 1550.0f));
	Platform platform30(nullptr, sf::Vector2f(180.0f, 0.5f), sf::Vector2f(1948.0f, 1550.0f));
	Platform platform31(nullptr, sf::Vector2f(180.0f, 0.5f), sf::Vector2f(300.0f, 1650.0f));
	Platform platform32(nullptr, sf::Vector2f(1.0f, 87.0f), sf::Vector2f(213.0f, 1600.0f));
	Platform platform33(nullptr, sf::Vector2f(340.0f, 0.5f), sf::Vector2f(1227.0f, 1665.0f));
	Platform platform34(nullptr, sf::Vector2f(1.0f, 87.0f), sf::Vector2f(1365.0f, 1580.0f));
	Platform platform35(nullptr, sf::Vector2f(40.0f, 2.0f), sf::Vector2f(1500.0f, 830.0f));
	Platform platform36(nullptr, sf::Vector2f(40.0f, 2.0f), sf::Vector2f(1272.0f, 830.0f));
	Platform platform37(nullptr, sf::Vector2f(45.0f, 5.0f), sf::Vector2f(824.0f, 830.0f));
	Platform platform38(nullptr, sf::Vector2f(90.0f, 0.5f), sf::Vector2f(1315.0f, 300.0f));
	Platform platform39(nullptr, sf::Vector2f(45.0f, 0.5f), sf::Vector2f(1050.0f, 316.0f));
	//map2
	Platform platform40(nullptr, sf::Vector2f(362.0f, 730.0f), sf::Vector2f(2472.0f, 1500.0f));
	Platform platform41(nullptr, sf::Vector2f(367.0f, 970.0f), sf::Vector2f(2481.0f, 455.0f));
	Platform platform42(nullptr, sf::Vector2f(1905.0f, 85.0f), sf::Vector2f(3709.0f, 26.0f));
	Platform platform43(nullptr, sf::Vector2f(800.0f, 160.0f), sf::Vector2f(3000.0f, 1791.0f));
	Platform platform44(nullptr, sf::Vector2f(940.0f, 160.0f), sf::Vector2f(4152.0f, 1794.0f));
	Platform platform45(nullptr, sf::Vector2f(223.0f, 1200.0f), sf::Vector2f(4446.0f, 1062.0f));
	Platform platform46(nullptr, sf::Vector2f(80.0f, 120.0f), sf::Vector2f(2717.0f, 166.0f));
	Platform platform47(nullptr, sf::Vector2f(216.0f, 139.0f), sf::Vector2f(2938.0f, 473.0f));
	Platform platform48(nullptr, sf::Vector2f(208.0f, 120.0f), sf::Vector2f(4090.0f, 1404.0f));
	Platform platform49(nullptr, sf::Vector2f(457.0f, 109.0f), sf::Vector2f(3112.0f, 1136.0f));
	Platform platform50(nullptr, sf::Vector2f(398.0f, 209.0f), sf::Vector2f(3758.0f, 1125.0f));
	Platform platform51(nullptr, sf::Vector2f(150.0f, 173.0f), sf::Vector2f(3255.0f, 805.0f));
	Platform platform52(nullptr, sf::Vector2f(77.0f, 101.0f), sf::Vector2f(3115.0f, 846.0f));
	Platform platform53(nullptr, sf::Vector2f(20.0f, 10.0f), sf::Vector2f(2700.0f, 929.0f));
	Platform platform54(nullptr, sf::Vector2f(400.0f, 37.0f), sf::Vector2f(3050.0f, 1229.0f));
	Platform platform55(nullptr, sf::Vector2f(180.0f, 1.0f), sf::Vector2f(2915.0f, 1487.0f));
	Platform platform56(nullptr, sf::Vector2f(180.0f, 1.0f), sf::Vector2f(3240.0f, 1484.0f));
	Platform platform57(nullptr, sf::Vector2f(5.0f, 241.0f), sf::Vector2f(2833.0f, 1362.0f));
	Platform platform58(nullptr, sf::Vector2f(2.0f, 241.0f), sf::Vector2f(3340.0f, 1367.0f));
	Platform platform59(nullptr, sf::Vector2f(10.0f, 20.0f), sf::Vector2f(3600.0f, 1473.0f));
	Platform platform60(nullptr, sf::Vector2f(769.0f, 20.0f), sf::Vector2f(3940.0f, 977.0f));
	Platform platform61(nullptr, sf::Vector2f(5.0f, 135.0f), sf::Vector2f(3550.0f, 890.0f));
	Platform platform62(nullptr, sf::Vector2f(600.0f, 240.0f), sf::Vector2f(3860.0f, 685.0f));
	Platform platform63(nullptr, sf::Vector2f(145.0f, 80.0f), sf::Vector2f(4350.0f, 326.0f));
	Platform platform64(nullptr, sf::Vector2f(149.0f, 500.0f), sf::Vector2f(4515.0f, 237.0f));
	Platform platform65(nullptr, sf::Vector2f(300.0f, 10.0f), sf::Vector2f(4000.0f, 361.0f));
	Platform platform66(nullptr, sf::Vector2f(800.0f, 10.0f), sf::Vector2f(3240.0f, 359.0f));
	Platform platform67(nullptr, sf::Vector2f(300.0f, 10.0f), sf::Vector2f(3220.0f, 290.0f));
	Platform platform68(nullptr, sf::Vector2f(145.0f, 0.5f), sf::Vector2f(3132.0f, 190.0f));
	Platform platform69(nullptr, sf::Vector2f(0.5f, 120.0f), sf::Vector2f(3234.0f, 130.0f));
	Platform platform70(nullptr, sf::Vector2f(240.0f, 160.0f), sf::Vector2f(3392.0f, 110.0f));
	Platform platform71(nullptr, sf::Vector2f(480.0f, 358.0f), sf::Vector2f(3760.0f, 183.0f));
	//map3
	Platform platform72(nullptr, sf::Vector2f(1071.0f, 316.0f), sf::Vector2f(4030.0f, 2250.0f));
	Platform platform73(nullptr, sf::Vector2f(1045.0f, 400.0f), sf::Vector2f(2786.0f, 2178.0f));
	Platform platform74(nullptr, sf::Vector2f(280.0f, 650.0f), sf::Vector2f(4408.0f, 2565.0f));
	Platform platform75(nullptr, sf::Vector2f(375.0f, 1465.0f), sf::Vector2f(2458.0f, 3066.0f));
	Platform platform76(nullptr, sf::Vector2f(675.0f, 380.0f), sf::Vector2f(2976.0f, 3700.0f));
	Platform platform77(nullptr, sf::Vector2f(500.0f, 650.0f), sf::Vector2f(4400.0f, 3641.0f));
	Platform platform79(nullptr, sf::Vector2f(520.0f, 180.0f), sf::Vector2f(4460.0f, 3212.0f));
	Platform platform80(nullptr, sf::Vector2f(150.0f, 135.0f), sf::Vector2f(3700.0f, 2855.0f));
	//Platform platform81(nullptr, sf::Vector2f(590.0f, 227.0f), sf::Vector2f(2494.0f, 3282.0f));
	Platform platform82(nullptr, sf::Vector2f(540.0f, 150.0f), sf::Vector2f(3793.0f, 3676.0f));
	//Platform platform83(nullptr, sf::Vector2f(510.0f, 270.0f), sf::Vector2f(2987.0f, 3408.0f));
	Platform platform84(nullptr, sf::Vector2f(160.0f, 120.0f), sf::Vector2f(3694.0f, 3200.0f));
	Platform platform85(nullptr, sf::Vector2f(210.0f, 110.0f), sf::Vector2f(2931.0f, 2850.0f));
	Platform platform86(nullptr, sf::Vector2f(163.0f, 100.0f), sf::Vector2f(3245.0f, 2850.0f));
	Platform platform87(nullptr, sf::Vector2f(465.0f, 0.1f), sf::Vector2f(4005.0f, 2920.0f));
	Platform platform88(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(3950.0f, 2940.0f));
	Platform platform89(nullptr, sf::Vector2f(310.0f, 170.0f), sf::Vector2f(2985.0f, 3200.0f));
	Platform platform90(nullptr, sf::Vector2f(272.0f, 180.0f), sf::Vector2f(2802.0f, 2680.0f));
	Platform platform91(nullptr, sf::Vector2f(271.0f, 80.0f), sf::Vector2f(3099.0f, 2710.0f));
	Platform platform92(nullptr, sf::Vector2f(660.0f, 75.0f), sf::Vector2f(3625.0f, 3401.0f));
	Platform platform93(nullptr, sf::Vector2f(110.0f, 90.0f), sf::Vector2f(3350.0f, 3250.0f));
	Platform platform94(nullptr, sf::Vector2f(125.0f, 170.0f), sf::Vector2f(3838.0f, 3200.0f));
	Platform platform95(nullptr, sf::Vector2f(50.0f, 5.0f), sf::Vector2f(3936.0f, 3310.0f));
	Platform platform96(nullptr, sf::Vector2f(140.0f, 1.0f), sf::Vector2f(2739.0f, 3250.0f));
	Platform platform97(nullptr, sf::Vector2f(20.0f, 0.5f), sf::Vector2f(3186.0f, 3260.0f));
	Platform platform98(nullptr, sf::Vector2f(35.0f, 0.1f), sf::Vector2f(2803.0f, 2910.0f));

	//pokeball 
	sf::Texture ITEM;
	ITEM.loadFromFile("texture/pokebon.png");
	std::vector <Item> itemVector;
	//map1
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 305.0f, 1572.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 706.0f, 1540.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 988.0f, 1540.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1267.0f, 1540.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1343.0f, 1830.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 979.0f, 1830.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 925.0f, 950.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 2048.0f, 670.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1170.0f, 385.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 869.0f, 505.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 780.0f, 505.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 675.0f, 505.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1807.0f, 240.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 577.0f, 240.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1494.0f, 1628.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 2087.0f, 1628.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 1795.0f, 1550.0f));
	//map2
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 2964.0f, 830.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 2898.0f, 1350.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 3258.0f, 1450.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 4073.0f, 1294.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 4007.0f, 1081.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 2816.0f, 155.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 3007.0f, 155.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 4356.0f, 118.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 4050.0f, 290.0f));
	itemVector.push_back(Item(&ITEM, sf::Vector2u(6, 1), 0.08f, 3705.0f, 920.0f));


	//pointpokeball
	int countpoint = 0;
	//pointpokemon
	int countpointpokemon = 0;

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

	//bullet
	int checkBull = 0;
	sf::Texture BULLET;
	BULLET.loadFromFile("texture/pokeballspin2d.png");
	Bulletpoke BulleT(&BULLET, sf::Vector2u(4, 1), 0.15f, 600, view.getCenter());
	int countb = 0;
	sf::Clock timer;

	//pokeball :
	sf::Font font;
	font.loadFromFile("texture/PokemonFont.ttf");
	std::ostringstream point;
	sf::Text Score;
	Score.setCharacterSize(35);
	Score.setString(point.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::White);

	//pokemon ::
	sf::Font font1;
	font1.loadFromFile("texture/PokemonFont.ttf");
	std::ostringstream pointreal;
	sf::Text ScorePoint;
	ScorePoint.setCharacterSize(35);
	ScorePoint.setString(point.str());
	ScorePoint.setFont(font1);
	ScorePoint.setFillColor(sf::Color::White);

	//Enemy
	sf::Texture ENEMY;
	sf::Texture ENEMY1;
	sf::Texture POKEMON1;
	ENEMY.loadFromFile("texture/enemy-lr.png");
	ENEMY1.loadFromFile("texture/enemy-updown.png");
	POKEMON1.loadFromFile("texture/cointest.png");
	std::vector <Enemy> EnemyVector; //LeftRight
	std::vector <Enemy> EnemyVector1; //UpDown
	std::vector <Enemy> PokemonVector1;

	//Pokemon
	//solid
	sf::Texture turtle;
	sf::Texture cabigon;
	sf::Texture pikachu;
	sf::Texture metamon;
	//updown
	sf::Texture dragon;
	sf::Texture polliwog;
	sf::Texture draniti;
	sf::Texture lapras;
	//left right
	sf::Texture eevee;
	sf::Texture pink;
	sf::Texture mew;
	sf::Texture fish;

	std::vector <Pokemon> PokemonVector; //Solid
	std::vector <Pokemon> PokemonVector2; //UpDown
	std::vector <Pokemon> PokemonVector3; //LeftRight
	turtle.loadFromFile("texture/turtlesolidsleep.png");
	cabigon.loadFromFile("texture/cabigonsolid.png");
	pikachu.loadFromFile("texture/pikachusolid1.png");
	metamon.loadFromFile("texture/metamonsolid.png");
	dragon.loadFromFile("texture/dragon-updown.png");
	polliwog.loadFromFile("texture/polliwog-updown.png");
	draniti.loadFromFile("texture/draniti-updown.png");
	lapras.loadFromFile("texture/lapras-updownwater.png");
	eevee.loadFromFile("texture/eevee-lr.png");
	pink.loadFromFile("texture/pink-lr1.png");
	mew.loadFromFile("texture/mew-lr.png");
	fish.loadFromFile("texture/fish-lrwater.png");

	//Enemies map2
	//////Left-Right
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 2844.0f, 880.0f));
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 2845.0f, 725.0f));
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 2807.0f, 227.0f));
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 3407.0f, 531.0f));
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 4189.0f, 220.0f));
	//EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(8, 1), 0.08f, 4080.0f, 870.0f));
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 3100.0f, 1340.0f));
	EnemyVector.push_back(Enemy(&ENEMY, sf::Vector2u(2, 2), 0.08f, 4007.0f, 1176.0f));
	//////Up-Down
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(2, 2), 0.08f, 2703.0f, 1480.0f));
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(2, 2), 0.08f, 2790.0f, 353.0f));
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(2, 2), 0.08f, 3492.0f, 1249.0f));
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(2, 2), 0.08f, 4264.0f, 1143.0f));
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(2, 2), 0.08f, 4210.0f, 416.0f));
	EnemyVector1.push_back(Enemy(&ENEMY1, sf::Vector2u(2, 2), 0.08f, 3273.0f, 414.0f));

	///////////////////////----------------------------------/////////////////////////////////
	//POKEMON MAP3 for point
	//SOLID
	PokemonVector.push_back(Pokemon(&turtle, sf::Vector2u(2, 1), 0.08f, 2425.0f, 3415.0f));
	PokemonVector.push_back(Pokemon(&turtle, sf::Vector2u(2, 1), 0.08f, 2800.0f, 2620.0f));
	PokemonVector.push_back(Pokemon(&cabigon, sf::Vector2u(2, 1), 1.0f, 3500.0f, 3040.0f));
	PokemonVector.push_back(Pokemon(&cabigon, sf::Vector2u(2, 1), 1.0f, 2800.0f, 3370.0f));
	PokemonVector.push_back(Pokemon(&pikachu, sf::Vector2u(3, 1), 1.0f, 4117.0f, 2752.0f));
	PokemonVector.push_back(Pokemon(&pikachu, sf::Vector2u(3, 1), 1.0f, 3698.0f, 2478.0f));
	PokemonVector.push_back(Pokemon(&metamon, sf::Vector2u(2, 1), 1.0f, 3797.0f, 2973.0f));
	PokemonVector.push_back(Pokemon(&metamon, sf::Vector2u(2, 1), 1.0f, 2901.0f, 2994.0f));
	//LEFT-RIGHT
	PokemonVector3.push_back(Pokemon(&eevee, sf::Vector2u(2, 2), 0.08f, 3953.0f, 2463.0f));
	PokemonVector3.push_back(Pokemon(&eevee, sf::Vector2u(2, 2), 0.08f, 3043.0f, 2486.0f));
	PokemonVector3.push_back(Pokemon(&pink, sf::Vector2u(2, 2), 0.08f, 3110.0f, 3039.0f));
	PokemonVector3.push_back(Pokemon(&pink, sf::Vector2u(2, 2), 0.08f, 3635.0f, 3516.0f));
	PokemonVector3.push_back(Pokemon(&mew, sf::Vector2u(2, 2), 0.08f, 3511.0f, 2673.0f));
	PokemonVector3.push_back(Pokemon(&fish, sf::Vector2u(2, 2), 0.08f, 3730.0f, 3670.0f));
	PokemonVector3.push_back(Pokemon(&fish, sf::Vector2u(2, 2), 0.08f, 2950.0f, 3660.0f));
	///UP-DOWN
	PokemonVector2.push_back(Pokemon(&dragon, sf::Vector2u(3, 2), 0.08f, 2710.0f, 2993.0f));
	PokemonVector2.push_back(Pokemon(&polliwog, sf::Vector2u(2, 2), 0.08f, 3510.0f, 2758.0f));
	PokemonVector2.push_back(Pokemon(&draniti, sf::Vector2u(2, 2), 0.08f, 3992.0f, 2529.0f));
	PokemonVector2.push_back(Pokemon(&lapras, sf::Vector2u(2, 2), 0.08f, 3986.0f, 3610.0f));
	///////////////////////----------------------------------/////////////////////////////////

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

		//win sound
		if ((player.GetPosition().x >= 3363 && player.GetPosition().x <= 3473) && (player.GetPosition().y >= 3701 && player.GetPosition().y <= 3770)) {
			soundTake.play();
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
		platform24.Draw(window);
		platform25.Draw(window);
		platform26.Draw(window);
		platform27.Draw(window);
		platform28.Draw(window);
		platform29.Draw(window);
		platform30.Draw(window);
		platform31.Draw(window);
		platform32.Draw(window);
		platform33.Draw(window);
		platform34.Draw(window);
		platform35.Draw(window);
		platform36.Draw(window);
		platform37.Draw(window);
		platform38.Draw(window);
		platform39.Draw(window);
		platform40.Draw(window);
		platform41.Draw(window);
		platform42.Draw(window);
		platform43.Draw(window);
		platform44.Draw(window);
		platform45.Draw(window);
		platform46.Draw(window);
		platform47.Draw(window);
		platform48.Draw(window);
		platform49.Draw(window);
		platform50.Draw(window);
		platform51.Draw(window);
		platform52.Draw(window);
		platform53.Draw(window);
		platform54.Draw(window);
		platform55.Draw(window);
		platform56.Draw(window);
		platform57.Draw(window);
		platform58.Draw(window);
		platform59.Draw(window);
		platform60.Draw(window);
		platform61.Draw(window);
		platform62.Draw(window);
		platform63.Draw(window);
		platform64.Draw(window);
		platform65.Draw(window);
		platform66.Draw(window);
		platform67.Draw(window);
		platform68.Draw(window);
		platform69.Draw(window);
		platform70.Draw(window);
		platform71.Draw(window);
		platform72.Draw(window);
		platform73.Draw(window);
		platform74.Draw(window);
		platform75.Draw(window);
		platform76.Draw(window);
		platform77.Draw(window);
		platform79.Draw(window);
		platform80.Draw(window);
		//platform81.Draw(window);
		platform82.Draw(window);
		//platform83.Draw(window);
		platform84.Draw(window);
		platform85.Draw(window);
		platform86.Draw(window);
		platform87.Draw(window);
		platform88.Draw(window);
		platform89.Draw(window);
		platform90.Draw(window);
		platform91.Draw(window);
		platform92.Draw(window);
		platform93.Draw(window);
		platform94.Draw(window);
		platform95.Draw(window);
		platform96.Draw(window);
		platform97.Draw(window);
		platform98.Draw(window);

		//pokeview
		if (pos.x > 210) {
			statepoke.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke1.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke2.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke3.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke4.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
			statepoke5.setPosition(sf::Vector2f(view.getCenter().x - 530, view.getCenter().y - 360));
		}

		//point pokeball
		point.str(" ");
		point << "pokeball :  " << countpoint;
		Score.setString(point.str());
		Score.setPosition({ view.getCenter().x - 300 ,view.getCenter().y - 335 });
		//plus point
		for (int i = 0; i < itemVector.size(); i++) {
			if (itemVector[i].iscollide() == 1)
			{
				soundTake.play();
				countpoint += 1;
				countb += 1;
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
		for (int i = 0; i < PokemonVector1.size(); i++)
		{
			PokemonVector1[i].update1(deltaTime);
		}

		//Update Pokemon
		for (int i = 0; i < PokemonVector.size(); i++)
		{
			PokemonVector[i].update(deltaTime, BulleT);
		}
		for (int i = 0; i < PokemonVector2.size(); i++)
		{
			PokemonVector2[i].update1(deltaTime, BulleT);
		}
		for (int i = 0; i < PokemonVector3.size(); i++)
		{
			PokemonVector3[i].update2(deltaTime, BulleT);
		}

		//point pokemon
		pointreal.str(" ");
		pointreal << "gotcha ! :  " << countpointpokemon;
		ScorePoint.setString(pointreal.str());
		ScorePoint.setPosition({ view.getCenter().x + 300 ,view.getCenter().y - 335 });

		//plus point
		for (int i = 0; i < PokemonVector.size(); i++) {
			if (PokemonVector[i].isBul() == 1)
			{
				countpointpokemon += 1;
				soundKeep.play();
			}
		}
		for (int i = 0; i < PokemonVector2.size(); i++) {
			if (PokemonVector2[i].isBul() == 1)
			{
				countpointpokemon += 1;
				soundKeep.play();
			}
		}
		for (int i = 0; i < PokemonVector3.size(); i++) {
			if (PokemonVector3[i].isBul() == 1)
			{
				countpointpokemon += 1;
				soundKeep.play();
			}
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
		for (int i = 0; i < PokemonVector1.size(); i++)
		{
			PokemonVector1[i].draw(window);
		}

		//Draw Pokemon
		for (int i = 0; i < PokemonVector.size(); i++)
		{
			PokemonVector[i].draw(window);
		}
		//add new
		for (int i = 0; i < PokemonVector2.size(); i++)
		{
			PokemonVector2[i].draw(window);
		}
		for (int i = 0; i < PokemonVector3.size(); i++)
		{
			PokemonVector3[i].draw(window);
		}

		//UPDATE PLAYER AND ENEMY
		player.UpdatePokemon1(deltaTime, PokemonVector1);
		player.UpdateEnemy1(deltaTime, EnemyVector1);
		player.UpdateEnemy(deltaTime, EnemyVector);

		//bulletpoke
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) &&
			timer.getElapsedTime().asSeconds() >= 0.5 && countb > 0)
		{
			timer.restart();
			countb--;
			countpoint--;
			bulletDirection = player.getFaceDirection();
			//UPDATE Bullet Pokemon
			for (int i = 0;i < PokemonVector.size();i++)
			{
				if (PokemonVector[i].isBul() == 1) {
					BulleT.deletepoke();
				}
			}

			checkBull = 1;
			if (bulletDirection == 1) {
				BulleT.attackL(pos);
			}
			else if (bulletDirection == 2) {
				BulleT.attackR(pos);
			}
			else if (bulletDirection == 3) {
				BulleT.attackU(pos);
			}
			else if (bulletDirection == 4) {
				BulleT.attackD(pos);
			}
		}
		if (checkBull == 1)
		{
			if (bulletDirection == 1) {
				BulleT.updateLEFT(deltaTime);
			}
			else if (bulletDirection == 2) {
				BulleT.updateRIGHT(deltaTime);
			}
			else if (bulletDirection == 3) {
				BulleT.updateUP(deltaTime);
			}
			else if (bulletDirection == 4) {
				BulleT.updateDOWN(deltaTime);
			}
			BulleT.draw(window);
		}
		if (abs(player.GetPosition().x - BulleT.GetPosition().x >= 1000.0f || abs(player.GetPosition().y) - BulleT.GetPosition().y >= 1000.0f))
		{
			checkBull = 0;
		}

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
		else if (countpoint == 16)window.draw(statepoke5);
		else if (countpoint == 17)window.draw(statepoke5);
		else if (countpoint == 18)window.draw(statepoke5);
		else if (countpoint == 19)window.draw(statepoke5);
		else if (countpoint == 20)window.draw(statepoke5);
		else if (countpoint == 21)window.draw(statepoke5);
		else if (countpoint == 22)window.draw(statepoke5);
		else if (countpoint == 23)window.draw(statepoke5);
		else if (countpoint == 24)window.draw(statepoke5);
		else if (countpoint == 25)window.draw(statepoke5);


		window.draw(Score);
		window.draw(ScorePoint);
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
		platform24.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform25.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform26.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform27.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform28.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform29.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform30.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform31.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform32.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform33.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform34.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform35.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform36.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform37.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform38.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform39.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform40.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform41.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform42.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform43.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform44.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform45.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform46.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform47.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform48.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform49.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform50.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform51.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform52.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform53.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform54.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform55.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform56.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform57.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform58.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform59.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform60.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform61.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform62.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform63.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform64.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform65.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform66.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform67.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform68.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform69.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform70.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform71.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform72.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform73.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform74.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform75.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform76.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform77.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform79.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform80.GetCollision().CheckCollision(playerCollision, 1.0f);
		//platform81.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform82.GetCollision().CheckCollision(playerCollision, 1.0f);
		//platform83.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform84.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform85.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform86.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform87.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform88.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform89.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform90.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform91.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform92.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform93.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform94.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform95.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform96.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform97.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform98.GetCollision().CheckCollision(playerCollision, 1.0f);

	}
	return 0;
}
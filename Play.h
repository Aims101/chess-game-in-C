
#include<iostream>
#include<SFML/Graphics.hpp>
#include"ChessBoard.h"
#include<fstream>

using namespace std;
using namespace sf;

const float width = 650.0;
const float heigth = 650.0;

class Play
{
private:
	sf::RectangleShape rectangle1;   // rectanggle to display initial play window with restart and play buttons
	sf::Texture BTex[3];             // button textures
	sf::Sprite BSprites[3];           //button sprites

public:
	Play();



};

Play::Play()
{
	sf::RenderWindow playWindow(sf::VideoMode(width, heigth),"Chess Game");

	BTex[0].loadFromFile("play-button.png");
	BTex[1].loadFromFile("refresh-button.png");
	BTex[2].loadFromFile("board.png");

	rectangle1.setSize(sf::Vector2f(width, heigth));
	BSprites[0].setTexture(BTex[0]);
	BSprites[1].setTexture(BTex[1]);
	BSprites[2].setTexture(BTex[2]);

	BSprites[0].setScale(2.0f, 2.0f);
	BSprites[1].setScale(2.0f, 2.0f);
	BSprites[2].setScale(0.73f, 0.73f);

	BSprites[0].setPosition(120, 20);
	BSprites[1].setPosition(400, 20);
	BSprites[2].setPosition(0, 0);

	rectangle1.setFillColor(sf::Color::White);

	while (playWindow.isOpen())
	{
		Vector2i MouPos = sf::Mouse::getPosition(playWindow);
		sf::Event evnt;
		while (playWindow.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
			{
				playWindow.close();

			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (BSprites[0].getGlobalBounds().contains(MouPos.x, MouPos.y))
				{
					playWindow.close();
					ChessBoard graphics;
					graphics.MainFunc(1);
				}
				if (BSprites[1].getGlobalBounds().contains(MouPos.x, MouPos.y))
				{
					playWindow.close();
					ifstream in1, in2;
					in1.open("spritepositions.txt");
					in2.open("boardpositions.txt");
					for (int i = 0; i < 64; i++)
					{
						int int1, int2;
						char chr1, chr2;
						in1 >> int1 >> chr1;
						SpritePositions[i] = int1;
						in2 >> int2 >> chr2;
						Board[i] = int2;
					}
					ChessBoard graphics;
					graphics.MainFunc(0);


				}
			}
		}
		playWindow.clear();
		playWindow.draw(rectangle1);
		playWindow.draw(BSprites[2]);
		playWindow.draw(BSprites[0]);
		playWindow.draw(BSprites[1]);
		playWindow.display();
	}



}
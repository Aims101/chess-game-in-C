#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<fstream>

using namespace std;
using namespace sf;

class Save
{
private:
	float width = 650.0;
	float height = 650.0;
public:
	Save() {}

	bool smain()
	{
		sf::RenderWindow window(sf::VideoMode(width,height), "Game of Chess ", sf::Style::Default);
		sf::Texture tex2[2];
		sf::Sprite sp2[2];
		tex2[0].loadFromFile("save-disk.png");
		tex2[1].loadFromFile("gameOver.png");

		sp2[0].setTexture(tex2[0]);
		sp2[0].setScale(2.0f, 2.0f);
		sp2[0].setPosition(250, 20);
		sp2[1].setTexture(tex2[1]);
		sp2[1].setScale(0.73f, 0.73f);
		sp2[1].setPosition(0, 0);

		while (window.isOpen())
		{
			sf::Vector2i Mpos = sf::Mouse::getPosition(window);
			sf::Event event1;
			while (window.pollEvent(event1))
			{
				if (event1.type == sf::Event::Closed)
				{
					window.close();
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (sp2[0].getGlobalBounds().contains(Mpos.x, Mpos.y))
					{
						return true;
						window.close();
					}
				}
			}
			window.clear();
			window.draw(sp2[1]);
			window.draw(sp2[0]);
			window.display();
		}
		return 0;
	}
};

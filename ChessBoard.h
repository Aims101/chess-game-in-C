#pragma once
#include<fstream>
#include<iostream>
#include<SFML/Graphics.hpp>
#include"PieceIdentity.h"
#include"SaveFunc.h"
using namespace std;
using namespace sf;




int SpritePositions[64] = { 0, 1, 2, 3, 4, 5, 6, 7,
							8, 9,10,11,12,13,14,15,
							64,64,64,64,64,64,64,64,
							64,64,64,64,64,64,64,64,
							64,64,64,64,64,64,64,64,
							64,64,64,64,64,64,64,64,
							48,49,50,51,52,53,54,55,
							56,57,58,59,60,61,62,63 };


int Board[64] = { -1,-2,-3,-4,-5,-3,-2,-1,
				 -6,-6,-6,-6,-6,-6,-6,-6,
				  0, 0, 0, 0, 0, 0, 0, 0,
				  0, 0, 0, 0, 0, 0, 0, 0,
				  0, 0, 0, 0, 0, 0, 0, 0,
				  0, 0, 0, 0, 0, 0, 0, 0,
				  6, 6, 6, 6, 6, 6, 6, 6,
				  1, 2, 3, 4, 5, 3, 2, 1 };
class ChessBoard
{
private: 
	const float BoardWidth = 650.0;
	const float BoardHeigth = 650.0;
	
public:

	
	void loadTextures(Texture textures[64]);
	void loadBoard(Texture textures[64], RectangleShape squares[64], Sprite sprites[64]);
	void MainFunc(int x);


};


void ChessBoard::loadTextures(Texture textures[64])  //to  load .png files of chess pieces into textures[64] array
{
	for (int i = 0; i < 64; i++)
	{
		if (SpritePositions[i] == 0 || SpritePositions[i] == 7)
		{
			
			textures[i].loadFromFile("blackRook.png");
		}else
		if (SpritePositions[i] == 1 || SpritePositions[i] == 6)
		{
			
			textures[i].loadFromFile("blackKnight.png");
		}else
		if (SpritePositions[i] == 2 || SpritePositions[i] == 5)
		{
			
			textures[i].loadFromFile("blackBishop.png");
		}else
		if (SpritePositions[i] == 3)
		{
			
			textures[i].loadFromFile("blackQueen.png");
		}else
		if (SpritePositions[i] == 4)
		{
			
			textures[i].loadFromFile("blackKing.png");
		}else
		if (SpritePositions[i] >= 8 || SpritePositions[i] <= 15)
		{
			
			textures[i].loadFromFile("blackPawn.png");
		}else
		if (SpritePositions[i] == 56 || SpritePositions[i] == 63)
		{
			
			textures[i].loadFromFile("whiteRook.png");
		}else
		if (SpritePositions[i] == 57 || SpritePositions[i] == 62)
		{
			
			textures[i].loadFromFile("whiteKnight.png");
		}else
		if (SpritePositions[i] == 58 || SpritePositions[i] == 61)
		{
			
			textures[i].loadFromFile("whiteBishop.png");
		} else
		if (SpritePositions[i] == 59)
		{
			
			textures[i].loadFromFile("whiteQueen.png");
		}else
		if (SpritePositions[i] == 60)
		{
			
			textures[i].loadFromFile("whiteKing.png");
		} else
		if (SpritePositions[i] >= 48 || SpritePositions[i] <= 55)
		{
		
			textures[i].loadFromFile("whitePawn.png");
		}

	}


}
void ChessBoard::loadBoard(Texture textures[64], RectangleShape squares[64], Sprite sprites[64])
{
	//float SquareWidth = BoardWidth / 8.0;
	//float SquareHeigth = BoardWidth / 8.0;


	for (int i = 0; i < 64; i++) //loop to set scale and set sprites loaded from files onto the sprites[] array
	{
		sprites[i].setTexture(textures[i]);
		sprites[i].setScale(1.7f, 1.7f);
	}
	for (int i = 0; i < 64; ++i)  // loop to set size of squares
	{
		squares[i].setSize(sf::Vector2f(BoardWidth / 8.0f, BoardHeigth / 8.0f));
	}

	int count = 0;  // counter to count the sqaures 
	for (int i = 0; i < 8; ++i)      // loop to increment x axis values 
	{
		for (int j = 0; j < 8; ++j)  //// loop to increment y axis values 
		{
			
			squares[count].setPosition(j * squares[count].getSize().y, i * squares[count].getSize().x);   //setting the position of squares
			sprites[count].setPosition(j * squares[count].getSize().y, i * squares[count].getSize().x);   //setting the position of sprites

			if ((i + j) % 2 == 0)    //setting the color of tiles
				squares[count].setFillColor(sf::Color::White);
			else//if((i + j) % 2 != 0)
				squares[count].setFillColor(sf::Color::Blue);
			count++;


		}


	}
}

void ChessBoard::MainFunc(int x) 
{
	sf::RenderWindow window(sf::VideoMode(BoardWidth, BoardHeigth), "Chess The Game Of Kings!", sf::Style::Default);
	sf::RectangleShape squares[64];
	sf::Texture textures[64];
	sf::Sprite sprites[64];
	loadTextures(textures);
	loadBoard(textures, squares, sprites);
	Identity Box;
	bool isMove;
	float dx, dy;
	sf::Vector2f newpos, oldpos;
	int n=0;  //to store initialtile
	int cc, turn = 1;//*&*
	int AllianceVal, position;  //AllianceVal***
	sf::Vector2f firstpos, secondpos;
	int v;
	int q[64];
	bool Cap = false;                 //***
	for (int i = 0; i < 64; ++i)
		q[i] = 64;
	while (window.isOpen())
	{
		sf::Vector2i Pos = sf::Mouse::getPosition(window);
		sf::Event event0;
		while (window.pollEvent(event0))
		{
			if (event0.type == sf::Event::Closed)
			{
				Save S;
				window.close();
				if (S.smain())   //smain=Save main
				{
					ofstream out1, out2;
					out1.open("spritepositions.txt");
					out2.open("boardpositions.txt");
					for (int i = 0; i < 64; i++)
					{
						out1 << SpritePositions[i] << ",";
						out2 << Board[i] << ",";

					}
					out1.close();
					out2.close();

				}
			}
				if (x != 0)  //x=1
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right))    ///right click to select a piece
					{
						for (int i = 0; i < 64; ++i) //i=0,=1,to 64
						{
							if (turn % 2 == 0 && Board[i] < 0)  //turn=1,
							{
								if (squares[i].getGlobalBounds().contains(Pos.x, Pos.y))
								{
									n = i;
									firstpos = squares[i].getPosition();
									v = SpritePositions[i];
									squares[n].setFillColor(sf::Color::Red);
									if (SpritePositions[n] != 64)
										Cap=true;                                //debug
									//break;
									  
									
								}
							}
						}
						for (int j = 0; j < 64; ++j)//j=0to47 no entry in if// j=48
						{
							if (turn % 2 != 0 && Board[j] > 0)//turn=1 n j=48 entry//
							{                                 //board[48]=6
								if (squares[j].getGlobalBounds().contains(Pos.x, Pos.y))
								{
									n = j;    // n=48
									firstpos = squares[j].getPosition();  
									v = SpritePositions[j];  //v=48
									squares[n].setFillColor(sf::Color::Red);  //red color on selected 
									if (SpritePositions[n] != 64)//!n=64
										Cap=true; //Cap=1
									//break;
								}
							}
						}
					}
					if (Cap != false)  //cap=1
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							for (int j = 0; j < 64; ++j)
							{
								if (squares[j].getGlobalBounds().contains(Pos.x,Pos.y))
								{
									//if(n==8 and j==16 and Board[n]==-6){ 
									isMove = Box.identifier(n, j, Board[n], Board);//boarnd[n]=6
									secondpos = squares[j].getPosition();
									int SpritePos = SpritePositions[n]; //SpritePositions[n]
									if (isMove) //==true
									{
										turn++;
										//q[j] = SpritePositions[j];
										//cc = q[j] ;    //***
										if (j != n)
										{
											sprites[SpritePos].setPosition(secondpos);  //sprites[n]
											//sprites[cc].setPosition(100000000, 100000000);//(100000000, 100000000)
											int tempPos = SpritePositions[j];
											SpritePositions[j] = SpritePositions[n];
											SpritePositions[n] = 64;
											if (Board[j] == 5 || Board[j] == -5)   // checks for checkmate
											{
												Save S;
												window.close();
												if (S.smain()==true)
												{
													ofstream out1, out2;
													out1.open("spritepositions.txt");
													out2.open("boardpositions.txt");
													for (int i = 0; i < 64; i++)
													{
														out1 << SpritePositions[i] << ",";
														out2 << Board[i] << ",";
													}
													out1.close();
													out2.close();

												}
											}
											if (j <= 63 && j >= 56 && Board[n] == -6)   // when pawn become queen
											{
												Board[j] = -4;
											}
											else if (j >= 0 && j <= 7 && Board[n] == 6)
											{
												Board[j] = 4;
											}
											else
											{
												Board[j] = Board[n];
												Board[n] = 0;
											}
											n = j;

										}
										/*int counter = 0;
										for (int i = 0; i < 8; i++)
										{
											for (int j = 0; j < 8; j++)
											{
												if ((i + j) % 2 == 0)
												{
													squares[counter].setFillColor(sf::Color::White);
												}
												else
												{
													squares[counter].setFillColor(sf::Color::Blue);
												}
												counter++;
											}
										}*/
									}
									int counter = 0;
									for (int i = 0; i < 8; ++i)
									{
										for (int j = 0; j < 8; ++j)
										{
											if ((i + j) % 2 == 0)
											{
												squares[counter].setFillColor(sf::Color::White);
											}
											else
											{
												squares[counter].setFillColor(sf::Color::Blue);
											}
											counter++;
										
										}
									}
								}
							}
							Cap = false;
						}
					}

				}
			
		}
		window.clear();

		for (int i = 0; i < 64; i++)
		{
			window.draw(squares[i]);
		}

		
		for (int i = 0; i < 64; i++)
		{
			if (SpritePositions[i]!= 64)

				window.draw(sprites[i]);
		}

		window.display();


	}
	
}








	

#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

class Piece
{
private:
	int ArrChess[64];
public:
	Piece(int arrChess[]);
	bool isTileOccupied(int Tile);
	string pieceAlliance(int Tile, string alliance);

};

Piece::Piece(int arrChess[])
{
	for (unsigned int i = 0; i < 64; i++)
	{
		ArrChess[i] = arrChess[i];
	}

	
}
bool Piece::isTileOccupied(int Tile)
{
	for (int i = 0; i < 64; i++)
	{
		if (ArrChess[Tile] == 0)
			return false;
		else
			return true;
	}

}

string Piece::pieceAlliance(int  Tile, string alliance)
{
	if (alliance == "white" )
	{
		if (ArrChess[Tile] < 0)
			return "black";
		else
			return "white";
	}
	else if (alliance == "black" )
	{
		if (ArrChess[Tile] > 0)
			return "white";
		else
			return "black";
			
	}
}


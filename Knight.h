#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Piece.h"
#include<vector>
using namespace std;
using namespace sf;

class Knight
{
private:
	const int Cand_Move_Coordinates[8] = { -17, -15, -10, -6, 6, 10, 15, 17 };
	int PieceTile;
	std::string Alliance;
	int ArrChess[64];
public:
	Knight(int tile, std::string alliance, int arrChess[]);
	bool isValidTileCoordinate(int currentCandidate);

	bool EightColumn(int tile, int offset);
	bool FirstColumn(int tile, int offset);
	bool SecondColumn(int tile, int offset);
	bool SeventhColumn(int tile, int offset);

	std::vector<int> getlegalMoves();
};

Knight::Knight(int tile, string alliance, int arrChess[])
{
	for (int i = 0; i < 64; i++)
	{
		ArrChess[i] = arrChess[i];
	}
	this->PieceTile = tile;
	this->Alliance = alliance;

}

bool Knight::isValidTileCoordinate(int currentCandidate)
{
	return currentCandidate >= 0 && currentCandidate <= 64;
}

bool Knight::EightColumn(int tile, int offset) 
{
	int eightColArr[8] = { 7,15,23,31,39,47,55,63 };
	bool temp=false;

	for (int i : eightColArr)
	{
		if (tile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;

	}
	return temp && ((offset == -15) || (offset == -6) || (offset == 10) || (offset == 17));

}

bool Knight::FirstColumn(int tile, int offset)
{
	int firstColArr[8] = { 0,8,16,24,32,40,48,56 };
	bool temp=false;
	for(int i:firstColArr)
	{
		if (tile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;
	}
	return temp && ((offset == -17) || (offset == -10) || (offset == 6) || (offset == 15));
}
bool Knight::SecondColumn(int tile, int offset)
{
	int secondColArr[8] = { 1,9,17,25,33,41,49,57 };
	bool temp=false;

	for (int i: secondColArr)
	{
		if (tile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;
	}
	return temp && ((offset == -10) || (offset == 6));
}
bool Knight::SeventhColumn(int tile, int offset)
{
	int seventhColArr[8] = { 6,14,22,30,38,46,54,62 };
	bool temp=false;
	for(int i:seventhColArr)
	{
		if (tile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;
	}
	return temp && ((offset == -6) || (offset == 10));
}
std::vector<int> Knight::getlegalMoves()
{
	Piece destinationTile(ArrChess);
	int possibleDestTile;
	std::vector<int> LegalMoves;

	for (int offset : Cand_Move_Coordinates)
	{
		if ((FirstColumn(this->PieceTile, offset)) || (SecondColumn(this->PieceTile, offset)) || (SeventhColumn(this->PieceTile, offset)) || (EightColumn(this->PieceTile, offset)))
		{
			continue;
		}
		possibleDestTile = this->PieceTile + offset;
		if (destinationTile.isTileOccupied(possibleDestTile))
		{
			if (this->Alliance != destinationTile.pieceAlliance(possibleDestTile, this->Alliance))
			{
				LegalMoves.push_back(possibleDestTile);
			}
		}
		else
			LegalMoves.push_back(possibleDestTile);

	}
	return LegalMoves;
}
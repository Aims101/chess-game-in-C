#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Piece.h"
using namespace std;
using namespace sf;


class King
{
private:
	const int Cand_Move_Coordinates[8] = { -9, -8, -7, -1, 1, 8, 7, 9 };
	int ArrChess[64];
	string Alliance;
	int PieceTile;

public:
	King(int tile, string alliance, int arrChess[]);
	bool isValidTileCoordinate(int currentCandidate);

	bool EightColumn(int tile, int offset);
	bool FirstColumn(int tile, int offset);

	std::vector<int> getLegalMoves();
};

King::King(int tile, string alliance, int arrChess[])
{
	for (int i = 0; i < 64; i++)
	{
		ArrChess[i] = arrChess[i];
	}
	this->PieceTile = tile;
	this->Alliance = alliance;

}
bool King::isValidTileCoordinate(int currentCandidate)
{
	return currentCandidate >= 0 && currentCandidate <= 64;
}
bool King::EightColumn(int tile, int offset)
{
	int eightColArr[8] = { 7,15,23,31,39,47,55,63 };
	bool temp=false;

	for (int i : eightColArr)
	{
		if (PieceTile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;

	}
	return temp && (offset == -7 || offset == 1 || offset == 9);

}
bool King::FirstColumn(int tile, int offset)
{
	int firstColArr[8] = { 0,8,16,24,32,40,48,56 };
	bool temp=false;

	for (int i : firstColArr)
	{
		if (PieceTile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;

	}
	return temp && (offset == 7 || offset == -1 || offset == -9);

}

std::vector<int> King::getLegalMoves()
{
	Piece destinationTile(ArrChess);
	int possibleDestTile = this->PieceTile;
	std::vector<int> LegalMoves;

	for (int offset : Cand_Move_Coordinates)
	{
		if (EightColumn(this->PieceTile, offset) || FirstColumn(this->PieceTile, offset))
		{
			continue;
		}
		possibleDestTile = this->PieceTile + offset;
		if (isValidTileCoordinate(possibleDestTile))
		{
			if (destinationTile.isTileOccupied(possibleDestTile))
			{
				if (this->Alliance != destinationTile.pieceAlliance(possibleDestTile, Alliance))
				{
					LegalMoves.push_back(possibleDestTile);
				}
			}
			else
			{
				LegalMoves.push_back(possibleDestTile);
			}
		}
	}
	return LegalMoves;
}
#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Piece.h"
using namespace std;
using namespace sf;

class Queen
{
private:
	const int Cand_Move_Coordinates[8] = { -8, -1, 1, 8, -9, -7, 9, 7 };
	int ArrChess[64];
	std::string Alliance;
	int PieceTile;

public:
	Queen(const int tile, string alliance, int arrChess[]);
	bool isValidTileCoordinate(int currentCandidate);

	bool EightColumn(int tile, int offset);
	bool FirstColumn(int tile, int offset);
	
	std::vector<int> getlegalMoves();
};
Queen::Queen(const int tile, string alliance, int arrChess[])
{
	for (int i = 0; i < 64; ++i)
	{
		ArrChess[i] = arrChess[i];
	}
	this->PieceTile = tile;
	this->Alliance = alliance;

}

bool Queen::isValidTileCoordinate(int currentCandidate)
{
	return currentCandidate >= 0 && currentCandidate < 64;
}

bool Queen::EightColumn(int tile, int offset)
{
	int eightColArr[8] = { 7,15,23,31,39,47,55,63 };
	bool temp;

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
	return temp && (offset == 1 || offset == -7 || offset == 9);
}
bool Queen::FirstColumn(int tile, int offset)
{
	int firstColArr[8] = { 0,8,16,24,32,40,43,56 };
	bool temp;
	for (int i : firstColArr)
	{
		if (tile == i)
		{
			temp = true;
			break;
		}
		else
			temp = false;
	}
	return temp && (offset == -1 || offset == 7 || offset == -9);
}
std::vector<int> Queen::getlegalMoves()
{
	Piece destinationTile(ArrChess);
	int possibleDestTile;
	std::vector<int> LegalMoves;

	for (int offset : Cand_Move_Coordinates)
	{
		possibleDestTile = this->PieceTile;
		/*if (firstColum(possibleDestinationTile, offset) || eighthColum(possibleDestinationTile, offset))
		{
			continue;
		}*/

		while (isValidTileCoordinate(possibleDestTile))
		{
			int temp = possibleDestTile;
			possibleDestTile += offset;
			if (FirstColumn(temp, offset) || EightColumn(temp, offset))
			{
				continue;
			}
			if (isValidTileCoordinate(possibleDestTile))
			{
				if (!destinationTile.isTileOccupied(possibleDestTile))
				{
					LegalMoves.push_back(possibleDestTile);
				}
				else
				{
					if (this->Alliance != destinationTile.pieceAlliance(possibleDestTile, this->Alliance))
					{
						LegalMoves.push_back(possibleDestTile);
					}
					break;
				}
			}
		}
	}
	return LegalMoves;
}


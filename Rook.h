#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Piece.h"
using namespace std;

class Rook
{
private:
	const int Cand_Move_Coordinates[4] = { -8, -1, 1, 8 };
	int ArrChess[64];
	std::string Alliance;
	int PieceTile;

public:
	Rook(int tile, string alliance, int arrChess[]);
	bool isValidTileCoordinate(int currentCandidate);

	bool EightColumn(int tile, int offset);
	bool FirstColumn(int tile, int offset);

	std::vector<int> getlegalMoves();
};
Rook::Rook(int tile, string alliance, int arrChess[])
{
	for (int i = 0; i < 64; i++)
	{
		ArrChess[i] = arrChess[i];
	}
	this->PieceTile = tile;
	this->Alliance = alliance;

}

bool Rook::isValidTileCoordinate(int currentCandidate)
{
	return currentCandidate >= 0 && currentCandidate < 64;
}
bool Rook::EightColumn(int tile, int offset)
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
	return temp && (offset == 1);
}
bool Rook::FirstColumn(int tile, int offset)
{
	int firstColArr[8] = { 0,8,16,24,32,40,48,56 };
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
	return temp && (offset == -1);
}
std::vector<int> Rook::getlegalMoves()
{
	Piece destinationTile(ArrChess);
	int possibleDestTile;
	std::vector<int> LegalMoves;

	for (int offset : Cand_Move_Coordinates)
	{
		possibleDestTile = this->PieceTile;
		if (FirstColumn(possibleDestTile, offset) || EightColumn(possibleDestTile, offset))
		{
			continue;
		}
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
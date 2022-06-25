#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Piece.h"
using namespace std;
using namespace sf;

class Pawn
{
private:
	const int Cand_Move_Coordinates[4] = { 7,8,9,16 };
	int PieceTile;
	int ArrChess[64];
	string Alliance;
	signed int direction;         //signed int because less than 0 represnt black pieces and greater than 0 represent white pieces

public:
	Pawn(int tile, string alliance, int arrChess[]);

	bool isValidTileCoordinate(int currentCand);

	bool EightColumn(int tile);
	bool FirstColumn(int tile);
	bool isfirstmove(int tile);

	std::vector<int> get_legal_moves();    //for calculations of available moves

};

Pawn::Pawn(int tile, string alliance, int arrChess[])
{
	for (int i = 0; i < 64; i++)
	{
		ArrChess[i] = arrChess[i];
	}
	this->PieceTile = tile;
	this->Alliance = alliance;

	if (this->Alliance == "white")
		direction = -1;
	else if (this->Alliance == "black")
		direction = 1;
}

bool Pawn::isValidTileCoordinate(int currentCandidate)
{
	return (currentCandidate >= 0 && currentCandidate <= 64);

}

bool Pawn::EightColumn(int tile)
{
	int eigthColArr[8] = { 7,15,23,31,39,47,55,63 };
	bool temp=false;
	for (int i = 0; i < 8; i++)
	{
		if (tile == eigthColArr[i])
		{
			temp = true;
			break;
		}
		else
			temp = false;
	}
	return temp;
}

bool Pawn::FirstColumn(int tile)
{
	int firstColArr[8] = { 0,8,16,24,32,40,48,56 };
	bool temp=false;

	for (int i = 0; i < 8; i++)
	{
		if (tile == firstColArr[i])
		{
			temp = true;
			break;
		}
		else
			temp = false;
	}
	return temp;
}
bool Pawn::isfirstmove(int tile) 
{
	int secondRowArr[8] = { 8,9,10,11,12,13,14,15 };
	int seventhRowArr[8] = { 48,49,50,51,52,53,54,55 };

	if (Alliance == "black")
	{
		for (int i:secondRowArr)
		{
			if (tile == i)
			{
				return true;
			}

		}
	}
	else if (Alliance == "white")
	{
		for (int i: seventhRowArr)
		{
			if (tile == i)
			{
				return true;
			}
		}
	}
	return false;

}

std::vector<int> Pawn::get_legal_moves()
{
	Piece destinationTile(ArrChess);
	int possibleDestTile;
	std::vector<int> LegalMoves;

	for (int offset : Cand_Move_Coordinates)
	{
		possibleDestTile = this->PieceTile + (direction * offset);

		if (!isValidTileCoordinate(possibleDestTile))
		{
			continue;
		}
		if (offset == 8 && !destinationTile.isTileOccupied(possibleDestTile))
		{
			LegalMoves.push_back(possibleDestTile);
		}
		if (offset == 16 && isfirstmove(this->PieceTile))
		{
			int behindCandidate = this->PieceTile + (this->direction * 8);
			if (!destinationTile.isTileOccupied(behindCandidate) && !destinationTile.isTileOccupied(possibleDestTile))
			{
				LegalMoves.push_back(possibleDestTile);
			}
		}
		if (offset == 7 && !((EightColumn(this->PieceTile) && this->Alliance == "white") || (FirstColumn(this->PieceTile) && this->Alliance == "black")))
		{
			if (destinationTile.isTileOccupied(possibleDestTile))
			{
				if (this->Alliance != destinationTile.pieceAlliance(possibleDestTile, Alliance))
				{
					LegalMoves.push_back(possibleDestTile);
				}
			}
		}
		if (offset == 9 && !((EightColumn(this->PieceTile) && this->Alliance == "black") || (FirstColumn(this->PieceTile) && this->Alliance == "white")))
		{
			if (destinationTile.isTileOccupied(possibleDestTile))
			{
				if (this->Alliance != destinationTile.pieceAlliance(this->PieceTile, Alliance))
				{
					LegalMoves.push_back(possibleDestTile);
				}
			}
		}
		return LegalMoves;
	}

}
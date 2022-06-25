#pragma once
#include<iostream>
#include<vector>
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Pawn.h"
#include"Queen.h"
#include"Rook.h"

using namespace std;

class Identity
{
public:
	bool chessKing(int initialTile, int finalTile, std::string alliance, int arrChess[64])
	{
		King king1(initialTile, alliance, arrChess);

		std::vector<int> v1;
		v1 = king1.getLegalMoves();

		for (std::vector<int>::iterator itr1 = v1.begin(); itr1 != v1.end(); ++itr1)
		{
			if (*itr1 == finalTile)
			{
				return true;
			}
			
				
		}
		return false;
	}
	bool chessBishop(int initialTile, int finalTile, std::string alliance, int arrChess[64])
	{
		bishop bishop1(initialTile, alliance, arrChess);

		std::vector<int> v2;
		v2 = bishop1.getLegalMoves();

		for (std::vector<int>::iterator itr2 = v2.begin(); itr2 != v2.end(); ++itr2)
		{
			if (*itr2 == finalTile)
			{
				return true;
			}
			
				
		}
		return false;
	}
	bool chessKnight(int initialTile, int finalTile, std::string alliance, int arrChess[64])
	{
		Knight knight1(initialTile, alliance, arrChess);

		std::vector<int> v3;
		v3 = knight1.getlegalMoves();

		for (std::vector<int>::iterator itr3 = v3.begin(); itr3 != v3.end(); ++itr3)
		{
			if (*itr3 == finalTile)
			{
				return true;
			}
			
				
		}
		return false;
	}
	bool chessPawn(int initialTile, int finalTile, std::string alliance, int arrChess[64])
	{
		Pawn pawn1(initialTile, alliance, arrChess);

		std::vector<int> v4;
		v4 = pawn1.get_legal_moves();

		for (std::vector<int>::iterator itr4 = v4.begin(); itr4 != v4.end(); ++itr4)
		{
			if (*itr4 == finalTile)
			{
				return true;
			}
			
				
		}
		return false;
	}
	bool chessQueen(int initialTile, int finalTile, std::string alliance, int arrChess[64])
	{
		Queen queen1(initialTile, alliance, arrChess);

		std::vector<int> v5;
		v5 = queen1.getlegalMoves();

		for (std::vector<int>::iterator itr5 = v5.begin(); itr5 != v5.end(); ++itr5)
		{
			if (*itr5 == finalTile)
			{
				return true;
			}
			
			
		}
		return false;
	}
	bool chessRook(int initialTile, int finalTile, std::string alliance, int arrChess[64])
	{
		Rook rook1(initialTile, alliance, arrChess);

		std::vector<int> v6;
		v6 = rook1.getlegalMoves();

		for (std::vector<int>::iterator itr6 = v6.begin(); itr6 != v6.end(); ++itr6)
		{
			if (*itr6 == finalTile)
			{
				return true;
			}
			
				
		}
		return false;
	}

	std::string checkAlliance(int piece)
	{
		if (piece > 0)
			return "white";
		if (piece < 0)
			return "black";
	}

	bool identifier(int initialTile, int finalTile, int piece, int arrChess[64])
	{
		std::string Alliance = checkAlliance(piece);
		if (piece == -1 || piece == 1)
		{
			return chessRook(initialTile, finalTile, Alliance, arrChess);
		}
		if (piece == -2 || piece == 2)
		{
			return chessKnight(initialTile, finalTile, Alliance, arrChess);
		}
		if (piece == -3 || piece == 3)
		{
			return chessBishop(initialTile, finalTile, Alliance, arrChess);
		}
		if (piece == -4 || piece == 4)
		{
			return chessQueen(initialTile, finalTile, Alliance, arrChess);
		}
		if (piece == -5 || piece == 5)
		{
			return chessKing(initialTile, finalTile, Alliance, arrChess);
		}
		if (piece == -6 || piece == 6)
		{
			return chessPawn(initialTile, finalTile, Alliance, arrChess);
		}

	}
	
};




#include <iostream>
#include <string>

using namespace std;

const int Size = 8;

struct Position
{
	int X;
	int Y;
};

struct ChessPiece
{
	string Pos;

	bool Move(Position pos)
	{
		char x = Pos[0] + pos.X;
		if (x < 'A' || x > 'H')
			return false;

		char y = Pos[1] + pos.Y;
		if (y < '1' || y > '8')
			return false;

		Pos[0] = x;
		Pos[1] = y;
		return true;
	}

	bool operator ==(const ChessPiece& other) const
	{
		return Pos == other.Pos;
	}
};

int main()
{
	ChessPiece King, Stone;
	string input;
	int Moves;

	cin >> King.Pos >> Stone.Pos >> Moves;

	while (Moves--)
	{
		ChessPiece tempKing{ King.Pos };
		ChessPiece tempStone{ Stone.Pos };
		Position d;

		cin >> input;
		if (input == "R")  d = {  1,  0 };
		if (input == "RB") d = {  1, -1 };
		if (input == "B")  d = {  0, -1 };
		if (input == "LB") d = { -1, -1 };
		if (input == "L")  d = { -1,  0 };
		if (input == "LT") d = { -1,  1 };
		if (input == "T")  d = {  0,  1 };
		if (input == "RT") d = {  1,  1 };

		if (tempKing.Move(d))
		{
			if (tempKing == tempStone)
			{
				if (tempStone.Move(d))
					Stone.Move(d);
				else
					continue;
			}

			King.Move(d);
		}
	}

	cout << King.Pos << "\n" << Stone.Pos << "\n";
}
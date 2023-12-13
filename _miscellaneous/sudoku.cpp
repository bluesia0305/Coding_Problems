#include <iostream>
#include <vector>

using namespace std;

struct Coord
{
	int Row;
	int Col;
};

int Sudoku[9][9];
vector<Coord> Blanks;
int Filled;

bool IsFillable(Coord coord, int n)
{
	int row = coord.Row, col = coord.Col;
	int mask = 0;

	for (int i = 0; i < 9; i++)
	{
		if (Sudoku[row][i])
			mask |= 1 << (Sudoku[row][i] - 1);

		if (Sudoku[i][col])
			mask |= 1 << (Sudoku[i][col] - 1);
	}

	int rStart = row / 3 * 3;
	int cStart = col / 3 * 3;
	for (int i = rStart; i < rStart + 3; i++)
		for (int j = cStart; j < cStart + 3; j++)
			if (Sudoku[i][j])
				mask |= 1 << (Sudoku[i][j] - 1);

	return ~mask >> (n - 1) & 1;
}

void FillBlanks()
{
	Coord blank = Blanks[Filled];
	for (int i = 1; i <= 9; i++)
	{
		// fill the blank if i is a fillable number
		if (IsFillable(blank, i))
		{
			Sudoku[blank.Row][blank.Col] = i;
			Filled++;
			if (Filled < Blanks.size())
				FillBlanks();	// recursion
		}
	}

	// backtrack to blank
	if (Filled != Blanks.size())
	{
		Sudoku[blank.Row][blank.Col] = 0;
		Filled--;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> Sudoku[i][j];
			if (!Sudoku[i][j])
				Blanks.push_back(Coord{ i, j });
		}

	if (!Blanks.empty())
		FillBlanks();

	// print
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << Sudoku[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
#include <iostream>

using namespace std;

int N;
int Count;
int Placed[15][15];

// test-----------------------------------------------
#include <vector>
struct Coord
{
	int X;
	int Y;
};
vector<Coord> Queens;

void PrintChessBoard()
{
	cout << "\n";
	char chess[15][15] = { 0, };
	memset(chess, '.', 15 * 15);

	for (Coord coord : Queens)
		chess[coord.Y][coord.X] = 'Q';

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << chess[i][j] << " ";
		cout << "\n";
	}
}
// test-----------------------------------------------

void SubordinatePaths(int x, int y, bool bEliminate)
{
	int left = x, right = x;
	int sign = bEliminate ? 1 : -1;

	// test-----------------------------------------------
	bEliminate ? Queens.push_back(Coord{ x, y - 1 }) : Queens.pop_back();
	// test-----------------------------------------------

	for (int i = y; i < N; i++)
	{
		Placed[i][x] += sign;
		if (--left >= 0) Placed[i][left] += sign;
		if (++right < N) Placed[i][right] += sign;
	}
}

void PlaceQueen(int X, int placedQueens)
{
	SubordinatePaths(X, placedQueens, true);

	if (placedQueens == N)
	{
		Count++;

		// test-----------------------------------------------
		PrintChessBoard();
		Queens.pop_back();
		// test-----------------------------------------------

		return;
	}

	for (int x = 0; x < N; x++)
		if (Placed[placedQueens][x] == 0)
			PlaceQueen(x, placedQueens + 1);

	SubordinatePaths(X, placedQueens, false);
}

int main()
{
	cin >> N;

	for (int x = 0; x < N; x++)
		PlaceQueen(x, 1);

	cout << "\n";
	cout << Count << "\n";
	return 0;
}
#include <iostream>

using namespace std;

struct Coord
{
	int X;
	int Y;
};

int N;
int Count;
int Placed[15][15];

void SubordinatePaths(int x, int y, bool bEliminate)
{
	int left = x, right = x;
	int sign = bEliminate ? 1 : -1;
	for (int i = y + 1; i < N; i++)
	{
		Placed[i][x] += sign;
		if (--left >= 0) Placed[i][left] += sign;
		if (++right < N) Placed[i][right] += sign;
	}
}

void PlaceQueen(int X, int placedQueens)
{
	SubordinatePaths(X, placedQueens, true);

	if (placedQueens == N - 1)
	{
		Count++;
		return;
	}

	for (int x = 0; x < N; x++)
		if (Placed[placedQueens + 1][x] == 0)
			PlaceQueen(x, placedQueens + 1);
	
	SubordinatePaths(X, placedQueens, false);
}

int main()
{
	cin >> N;

	for (int x = 0; x < N; x++)
		PlaceQueen(x, 0);

	cout << Count << "\n";
	return 0;
}
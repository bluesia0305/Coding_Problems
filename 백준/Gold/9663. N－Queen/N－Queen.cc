#include <iostream>

using namespace std;

int N;
int Count;
int Placed[15][15];

void SubordinatePaths(int x, int y, bool bEliminate)
{
	int left = x, right = x;
	int sign = bEliminate ? 1 : -1;
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

	cout << Count << "\n";
	return 0;
}
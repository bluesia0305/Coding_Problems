#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Coord
{
	int X;
	int Y;
};

int N;
int Count;
vector<Coord> Queens;

bool ValidPos(int x, int y)
{
	for (Coord coord : Queens)
		if (coord.X == x || coord.Y == y ||	abs(x - coord.X) == abs(y - coord.Y))
			return false;

	return true;
}

void PlaceQueens(int startX, int startY)
{
	Queens.push_back(Coord{ startX, startY });
	const int numQueens = Queens.size();

	if (numQueens < N)
	{
		for (int x = 0; x < N; x++)
			if (ValidPos(x, numQueens))
				PlaceQueens(x, numQueens);
	}
	else if (numQueens == N)
		Count++;

	Queens.pop_back();
}

int main()
{
	cin >> N;

	for (int x = 0; x < N; x++)
		PlaceQueens(x, 0);

	cout << Count << "\n";
	return 0;
}
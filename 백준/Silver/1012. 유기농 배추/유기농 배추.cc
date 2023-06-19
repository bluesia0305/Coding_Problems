#include <iostream>

using namespace std;

struct Coord
{
	int X;
	int Y;
};

int T, M, N, K;

void Expansion(int field[50][50], int x, int y)
{
	field[y][x] = 0;

	if (x - 1 >= 0 && field[y][x - 1])
		Expansion(field, x - 1, y);

	if (x + 1 < M && field[y][x + 1])
		Expansion(field, x + 1, y);

	if (y - 1 >= 0 && field[y - 1][x])
		Expansion(field, x, y - 1);

	if (y + 1 < N && field[y + 1][x])
		Expansion(field, x, y + 1);

}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		int worms = 0;
		int field[50][50] = { 0, };

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (field[i][j])
				{
					Expansion(field, j, i);
					worms++;
				}

		cout << worms << "\n";
	}

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int Map[8][8];
int N, M;
int Wall = 3;
int MaxSafeArea = 0;

struct Coord
{
	int X;
	int Y;
};

int CountSafeArea()
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!Map[i][j])
				count++;

	return count;
}

void Propagation()
{
	queue<Coord> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 2)
				q.push(Coord{ j, i });

	while (!q.empty())
	{
		Coord coord = q.front();
		q.pop();
		if (Map[coord.Y][coord.X] == 0)
			Map[coord.Y][coord.X] = 6;

		if (coord.X < M - 1 && !Map[coord.Y][coord.X + 1]) q.push(Coord{ coord.X + 1, coord.Y });
		if (coord.Y < N - 1 && !Map[coord.Y + 1][coord.X]) q.push(Coord{ coord.X, coord.Y + 1 });
		if (coord.X > 0 && !Map[coord.Y][coord.X - 1]) q.push(Coord{ coord.X - 1, coord.Y });
		if (coord.Y > 0 && !Map[coord.Y - 1][coord.X]) q.push(Coord{ coord.X, coord.Y - 1 });
	}

	int safeArea = CountSafeArea();
	if (MaxSafeArea < safeArea)
		MaxSafeArea = safeArea;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 6)
				Map[i][j] = 0;
}

void Backtracking(int x, int y)
{
	if (Map[y][x])
		return;

	Map[y][x] = Wall++;

	if (Wall < 6)
	{
		for (int i = y; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (i == y)
					if (j <= x)
						continue;

				Backtracking(j, i);
			}
	}

	if (Wall == 6)
		Propagation();

	Map[y][x] = 0;
	Wall--;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			Backtracking(j, i);

	cout << MaxSafeArea << "\n";
	return 0;
}
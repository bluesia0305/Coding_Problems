#include <iostream>
#include <queue>

using namespace std;

struct Coord { int X, Y, Time; };

int N;
int Fishes[20][20];
int TotalTime;
int Level = 2, Exp;

struct cmp
{
	bool operator()(Coord a, Coord b)
	{
		if (a.Time == b.Time)
		{
			if (a.X == b.X)
				return a.Y > b.Y;

			return a.X > b.X;
		}
		return a.Time > b.Time;
	}
};

bool Search(Coord& start)
{
	priority_queue<Coord, vector<Coord>, cmp> pq;
	pq.emplace(start);

	bool Visited[20][20] = { 0, };
	while (!pq.empty())
	{
		Coord coord = pq.top();
		pq.pop();

		if (Visited[coord.X][coord.Y] ||
			Fishes[coord.X][coord.Y] > Level)
			continue;

		if (Fishes[coord.X][coord.Y] > 0 &&
			Fishes[coord.X][coord.Y] < Level)
		{
			if (++Exp == Level)
			{
				Level++;
				Exp = 0;
			}

			Fishes[coord.X][coord.Y] = 0;
			TotalTime += coord.Time;
			start = { coord.X, coord.Y, 0 };

			return true;
		}

		if (coord.X - 1 >= 0)
			pq.emplace(Coord{ coord.X - 1, coord.Y, coord.Time + 1 });

		if (coord.Y - 1 >= 0)
			pq.emplace(Coord{ coord.X, coord.Y - 1, coord.Time + 1 });

		if (coord.Y + 1 <= N - 1)
			pq.emplace(Coord{ coord.X, coord.Y + 1, coord.Time + 1 });

		if (coord.X + 1 <= N - 1)
			pq.emplace(Coord{ coord.X + 1, coord.Y, coord.Time + 1 });

		Visited[coord.X][coord.Y] = true;
	}

	return false;
}

int main()
{
	cin >> N;

	Coord start;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int fish;
			cin >> fish;

			if (fish != 9)
				Fishes[i][j] = fish;
			else
			{
				start = Coord{ i, j, 0 };
				Fishes[i][j] = 0;
			}
		}

	while (true)
		if (!Search(start))
			break;

	cout << TotalTime;
	return 0;
}
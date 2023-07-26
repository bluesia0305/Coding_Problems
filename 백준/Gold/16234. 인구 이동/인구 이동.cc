#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;

struct Coord
{
	int X;
	int Y;
};

int A[50][50];
bool Visited[50][50];
bool Unified[50][50];
int N, L, R, Count;

void Propagate(queue<Coord>& q, int x, int y, int dx, int dy)
{
	if (x + dx < 0 || x + dx > N - 1 ||
		y + dy < 0 || y + dy > N - 1)
		return;

	int diff = abs(A[y][x] - A[y + dy][x + dx]);
	if (!Visited[y + dy][x + dx] &&	diff >= L && diff <= R)
		q.emplace(Coord{ x + dx, y + dy });
}

bool Unify(int x, int y)
{
	memset(Visited, false, 50 * 50);
	int sum = 0;
	int count = 0;

	queue<Coord> q;
	q.emplace(Coord{ x, y });

	vector<Coord> Union;
	while (!q.empty())
	{
		Coord coord = q.front();
		q.pop();

		if (Unified[coord.Y][coord.X] || Visited[coord.Y][coord.X])
			continue;

		Visited[coord.Y][coord.X] = true;
		Union.emplace_back(Coord{ coord.X, coord.Y });
		sum += A[coord.Y][coord.X];
		count++;

		Propagate(q, coord.X, coord.Y,  1,  0);
		Propagate(q, coord.X, coord.Y,  0,  1);
		Propagate(q, coord.X, coord.Y, -1,  0);
		Propagate(q, coord.X, coord.Y,  0, -1);
	}
	
	int Num = sum / count;
	for (const Coord& c : Union)
	{
		A[c.Y][c.X] = Num;
		Unified[c.Y][c.X] = true;
	}

	return Union.size() > 1;
}

bool IsUnifyable()
{
	memset(Unified, false, 50 * 50);
	bool bUnifyable = false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!Unified[i][j])
				bUnifyable |= Unify(j, i);

	return bUnifyable;
}

int main()
{
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	while (IsUnifyable())
		Count++;

	cout << Count << "\n";
	return 0;
}
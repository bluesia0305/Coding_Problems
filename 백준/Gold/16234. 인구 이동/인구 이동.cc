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

int N, L, R, Sum, Days;
int A[50][50];
bool Visited[50][50];

int DX[4] = { 1, 0, -1, 0 };
int DY[4] = { 0, 1, 0, -1 };

queue<Coord> q;
vector<Coord> Union;

void FindUnion(int x, int y, int i)
{
	int row = y + DY[i];
	int col = x + DX[i];

	if (row < 0 || row > N - 1 ||
		col < 0 || col > N - 1 ||
		Visited[row][col])
		return;

	int diff = abs(A[y][x] - A[row][col]);
	if (diff >= L && diff <= R)
	{
		Visited[row][col] = true;
		Sum += A[row][col];
		Union.emplace_back(Coord{ col, row });
		q.emplace(Coord{ col, row });
	}
}

bool Unify(int x, int y)
{
	Visited[y][x] = true;
	Sum = A[y][x];

	Union.clear();
	Union.emplace_back(Coord{ x, y });
	q.emplace(Coord{ x, y });
	while (!q.empty())
	{
		Coord coord = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
			FindUnion(coord.X, coord.Y, i);
	}

	int Num = Sum / Union.size();
	for (const Coord& c : Union)
		A[c.Y][c.X] = Num;

	return Union.size() > 1;
}

int main()
{
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	while (true)
	{
		bool bExistUnion = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!Visited[i][j])
					bExistUnion |= Unify(j, i);

		if (bExistUnion)
		{
			Days++;
			memset(Visited, false, 50 * 50);
		}
		else
			break;
	}

	cout << Days << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int N, M;
int Paper[500][500];
bool Visited[500][500];
int Max, Sum, Count;

void FindByDFS(int x, int y)
{
	if (Visited[y][x])
		return;

	int value = Paper[y][x];
	Visited[y][x] = true;
	Sum += value;
	Count++;

	if (Count == 4)
	{
		Max = Sum > Max ? Sum : Max;
		Visited[y][x] = false;
		Sum -= value;
		Count--;
		return;
	}
							   
	if (x < M - 1)	FindByDFS(x + 1, y);
	if (y < N - 1)	FindByDFS(x, y + 1);
	if (x > 0)		FindByDFS(x - 1, y);

	Visited[y][x] = false;
	Sum -= value;
	Count--;
}

void FindManually(int x, int y)
{
	if (x < M - 2)
	{
		int temp = Paper[y][x] + Paper[y][x + 1] + Paper[y][x + 2];
		if (y > 0)		Max = temp + Paper[y - 1][x + 1] > Max ? temp + Paper[y - 1][x + 1] : Max;
		if (y < N - 1)	Max = temp + Paper[y + 1][x + 1] > Max ? temp + Paper[y + 1][x + 1] : Max;
	}

	if (y < N - 2)
	{
		int temp = Paper[y][x] + Paper[y + 1][x] + Paper[y + 2][x];
		if (x > 0)		Max = temp + Paper[y + 1][x - 1] > Max ? temp + Paper[y + 1][x - 1] : Max;
		if (x < M - 1)	Max = temp + Paper[y + 1][x + 1] > Max ? temp + Paper[y + 1][x + 1] : Max;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Paper[i][j];

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			FindByDFS(x, y);
			FindManually(x, y);
		}

	cout << Max << "\n";
	return 0;
}
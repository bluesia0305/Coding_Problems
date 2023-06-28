#include <iostream>

using namespace std;

int N;
int Paper[128][128];
int White;
int Blue;

bool IsHomogeneous(int x, int y, int len)
{
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			if (Paper[y][x] != Paper[i][j])
				return false;

	return true;
}

void Partition(int x, int y, int len)
{
	int half = len / 2;
	if (IsHomogeneous(x, y, len))
	{
		if (Paper[y][x])
			Blue++;
		else
			White++;
	}
	else
	{
		Partition(x, y, half);
		Partition(x + half, y, half);
		Partition(x, y + half, half);
		Partition(x + half, y + half, half);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Paper[i][j];

	Partition(0, 0, N);

	cout << White << "\n" << Blue << "\n";
	return 0;
}
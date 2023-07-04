#include <iostream>

using namespace std;

int Data[64][64];

bool IsHomogeneous(int x, int y, int len)
{
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			if (Data[y][x] != Data[i][j])
				return false;

	return true;
}

void Partition(int x, int y, int len)
{
	int half = len / 2;
	if (IsHomogeneous(x, y, len))
		cout << Data[y][x];
	else
	{
		cout << "(";
		Partition(x, y, half);
		Partition(x + half, y, half);
		Partition(x, y + half, half);
		Partition(x + half, y + half, half);
		cout << ")";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char line[65] = { 0, };
		cin >> line;

		for (int j = 0; j < N; j++)
			Data[i][j] = line[j] == '1' ? 1 : 0;
	}

	Partition(0, 0, N);
	return 0;
}
#include <iostream>

using namespace std;

int N;
char Paper[2187][2187];
int Nums[3];

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
	if (IsHomogeneous(x, y, len))
		Nums[Paper[y][x]]++;
	else
	{
		len /= 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Partition(x + i * len, y + j * len, len);
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
		{
			int c;
			cin >> c;
			Paper[i][j] = c + 1;
		}

	Partition(0, 0, N);

	for (int num : Nums)
		cout << num << "\n";

	return 0;
}
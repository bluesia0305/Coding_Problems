#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int Expansion(int map[25][25], int count, int x, int y)
{
	map[y][x] = 0;
	count++;

	if (x - 1 >= 0 && map[y][x - 1])
		count = Expansion(map, count, x - 1, y);

	if (x + 1 < N && map[y][x + 1])
		count = Expansion(map, count, x + 1, y);

	if (y - 1 >= 0 && map[y - 1][x])
		count = Expansion(map, count, x, y - 1);

	if (y + 1 < N && map[y + 1][x])
		count = Expansion(map, count, x, y + 1);

	return count;
}

int main()
{
	cin >> N;

	string Houses[25];
	for (int i = 0; i < N; i++)
		cin >> Houses[i];

	int map[25][25] = { 0, };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = (Houses[i][j] - '0');

	vector<int> Complex;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j])
				Complex.push_back(Expansion(map, 0, j, i));

	sort(Complex.begin(), Complex.end());
	cout << Complex.size() << "\n";
	for (int c : Complex)
		cout << c << "\n";

	return 0;
}
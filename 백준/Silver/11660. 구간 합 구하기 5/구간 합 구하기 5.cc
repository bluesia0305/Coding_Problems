#include <iostream>

using namespace std;

int DP[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> DP[i][j];
			DP[i][j] += DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
		}

	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << DP[y2][x2] - DP[y1 - 1][x2] - DP[y2][x1 - 1] + DP[y1 - 1][x1 - 1] << "\n";
	}

	return 0;
}
#include <iostream>

using namespace std;

int Map[110][110];
unsigned long long DP[110][110];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];

	DP[1][1] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (int movement = Map[i][j])
			{
				DP[i + movement][j] += DP[i][j];
				DP[i][j + movement] += DP[i][j];
			}

	cout << DP[N][N];
	return 0;
}
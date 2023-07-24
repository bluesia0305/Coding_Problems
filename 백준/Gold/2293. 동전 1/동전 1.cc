#include <iostream>

using namespace std;

int DP[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	DP[0] = 1;
	while (N--)
	{
		int Coin;
		cin >> Coin;

		for (int j = Coin; j <= K; j++)
			DP[j] += DP[j - Coin];
	}

	cout << DP[K] << "\n";
	return 0;
}
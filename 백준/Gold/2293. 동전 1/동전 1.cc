#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> DP(K + 1);

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
#include <iostream>

using namespace std;

int DP[10001];
int Coins[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Coins[i];

	DP[0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = Coins[i]; j <= K; j++)
			DP[j] += DP[j - Coins[i]];

	cout << DP[K] << "\n";
	return 0;
}
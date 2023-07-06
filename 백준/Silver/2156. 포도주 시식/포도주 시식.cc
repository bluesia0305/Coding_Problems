#include <iostream>

using namespace std;

int Wines[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int dp[5] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		cin >> Wines[i];

		if (i < 3)
			dp[0] = dp[1] + Wines[i];
		else
		{
			int cand1 = Wines[i - 1] + (dp[4] > dp[3] ? dp[4] : dp[3]);
			int cand2 = dp[3] > dp[2] ? dp[3] : dp[2];
			dp[0] = Wines[i] + (cand1 > cand2 ? cand1 : cand2);
		}
		
		for (int i = 0; i < 4; i++)
			dp[4 - i] = dp[3 - i];
	}

	cout << (dp[1] > dp[2] ? dp[1] : dp[2]) << "\n";
	return 0;
}
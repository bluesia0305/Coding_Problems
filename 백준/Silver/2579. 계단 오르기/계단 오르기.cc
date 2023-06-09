#include <iostream>

using namespace std;

int Stairs[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int dp[4] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		cin >> Stairs[i];

		if (i > 2)
		{
			int score = Stairs[i - 1] + dp[0];
			dp[3] = Stairs[i] + (dp[1] > score ? dp[1] : score);

			dp[0] = dp[1];
			dp[1] = dp[2];
			dp[2] = dp[3];
		}
		else if (i == 1)
			dp[1] = Stairs[1];
		else if (i == 2)
			dp[2] = Stairs[1] + Stairs[2];
	}

	cout << (N > 2 ? dp[3] : dp[N]) << "\n";
	return 0;
}
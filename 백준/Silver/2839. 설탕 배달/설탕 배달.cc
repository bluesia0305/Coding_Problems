#include <iostream>

using namespace std;

int DP[5001];

int main()
{
	int N;
	cin >> N;

	DP[3] = 1;
	DP[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		int min;

		if (DP[i - 3])
		{
			if (DP[i - 5])
				min = DP[i - 3] < DP[i - 5] ? DP[i - 3] : DP[i - 5];
			else
				min = DP[i - 3];
		}
		else
		{
			if (DP[i - 5])
				min = DP[i - 5];
			else
				continue;
		}

		DP[i] = min + 1;
	}

	cout << (DP[N] ? DP[N] : -1) << "\n";
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M, Price[10001] = { 1, };
		cin >> N;

		vector<int> Coins(N);
		for (int i = 0; i < N; i++)
			cin >> Coins[i];

		cin >> M;
		for (int coin : Coins)
		{
			for (int i = 0; i <= M; i++)
			{
				if (i - coin >= 0)
					Price[i] += Price[i - coin];
			}
		}

		cout << Price[M] << "\n";
	}

	return 0;
}
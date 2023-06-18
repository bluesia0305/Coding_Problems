#include <iostream>

using namespace std;

int Degrees[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Degrees[i];

	int sum = 0;
	for (int i = 0; i < K; i++)
		sum += Degrees[i];

	int max = sum;
	for (int i = 1; i <= N - K; i++)
	{
		sum += Degrees[K + i - 1] - Degrees[i - 1];
		if (sum > max)
			max = sum;
	}

	cout << max << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int Buckets[100] = { 0, };
	int N, M;
	cin >> N >> M;

	while (M--)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int n = i - 1; n < j; n++)
			Buckets[n] = k;
	}

	for (int i = 0; i < N; i++)
		cout << Buckets[i] << " ";
	cout << "\n";

	return 0;
}
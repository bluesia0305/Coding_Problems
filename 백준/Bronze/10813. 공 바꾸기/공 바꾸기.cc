#include <iostream>

using namespace std;

int main()
{
	int Buckets[100];
	for (int i = 0; i < 100; i++)
		Buckets[i] = i + 1;

	int N, M;
	cin >> N >> M;

	while (M--)
	{
		int i, j, temp;
		cin >> i >> j;

		temp = Buckets[j - 1];
		Buckets[j - 1] = Buckets[i - 1];
		Buckets[i - 1] = temp;
	}

	for (int i = 0; i < N; i++)
		cout << Buckets[i] << " ";
	cout << "\n";

	return 0;
}
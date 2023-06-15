#include <iostream>

using namespace std;

char OpCounts[1000001];

int main()
{
	int N;
	cin >> N;

	int i = 1;
	while (i < N)
	{
		int temp = OpCounts[i] + 1;

		if (3 * i <= N)
			OpCounts[3 * i] = OpCounts[3 * i] ? OpCounts[3 * i] > temp ? temp : OpCounts[3 * i] : OpCounts[i] + 1;

		if (2 * i <= N)
			OpCounts[2 * i] = OpCounts[2 * i] ? OpCounts[2 * i] > temp ? temp : OpCounts[2 * i] : OpCounts[i] + 1;
		
		OpCounts[i + 1] = OpCounts[i + 1] ? OpCounts[i + 1] > temp ? temp : OpCounts[i + 1] : OpCounts[i] + 1;
		i++;
	}

	cout << (int)OpCounts[N] << "\n";
	return 0;
}
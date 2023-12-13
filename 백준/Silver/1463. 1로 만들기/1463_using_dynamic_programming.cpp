#include <iostream>
#include <algorithm>

using namespace std;

char Counts[1000001];

int main()
{
	int N;
	cin >> N;

	int i = 0;
	while (i++ < N)
	{
		char cnt = Counts[i] + 1;

		if (3 * i <= N)
			Counts[3 * i] = Counts[3 * i] ? min(Counts[3 * i], cnt) : cnt;

		if (2 * i <= N)
			Counts[2 * i] = Counts[2 * i] ? min(Counts[2 * i], cnt) : cnt;

		Counts[i + 1] = Counts[i + 1] ? min(Counts[i + 1], cnt) : cnt;
	}

	cout << (int)Counts[N] << "\n";
	return 0;
}
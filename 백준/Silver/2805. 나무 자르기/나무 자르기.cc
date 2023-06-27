#include <iostream>

using namespace std;

int N;
unsigned long long M;
unsigned Woods[1000000];

unsigned long long ObtainWoods(unsigned len)
{
	unsigned long long meters = 0;
	for (int i = 0; i < N; i++)
		if (Woods[i] > len)
			meters += Woods[i] - len;

	return meters;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	unsigned minLen = 1;
	unsigned maxLen = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> Woods[i];
		if (maxLen < Woods[i])
			maxLen = Woods[i];
	}

	maxLen++;
	while (minLen < maxLen)
	{
		unsigned middle = (minLen + maxLen) / 2;

		if (ObtainWoods(middle) < M)
			maxLen = middle;
		else
			minLen = middle + 1;
	}

	cout << maxLen - 1 << "\n";
	return 0;
}
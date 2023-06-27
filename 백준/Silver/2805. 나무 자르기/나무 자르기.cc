#include <iostream>

using namespace std;

int N, M;
int Woods[1000000];

unsigned long long ObtainWoods(unsigned len)
{
	unsigned long long meters = 0;
	for (int i = 0; i < N; i++)
		if (Woods[i] > (int)len)
			meters += Woods[i] - len;

	return meters;
}

int main()
{
	cin >> N >> M;

	unsigned long long minLen = 1;
	unsigned long long maxLen = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> Woods[i];
		if ((int)maxLen < Woods[i])
			maxLen = Woods[i];
	}

	maxLen++;
	while (minLen < maxLen)
	{
		unsigned long long middle = (minLen + maxLen) / 2;

		if (ObtainWoods(middle) < (unsigned long long)M)
			maxLen = middle;
		else
			minLen = middle + 1;
	}

	cout << maxLen - 1 << "\n";
	return 0;
}
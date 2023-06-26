#include <iostream>

using namespace std;

int K, N;
int Lines[10000];

int NumLines(size_t len)
{
	int count = 0;
	for (int i = 0; i < K; i++)
		count += Lines[i] / (int)len;

	return count;
}

int main()
{
	cin >> K >> N;

	size_t minLen = 1;
	size_t maxLen = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> Lines[i];
		if (maxLen < Lines[i])
			maxLen = Lines[i];
	}

	maxLen++;
	while (minLen < maxLen)
	{
		size_t middle = (minLen + maxLen) / 2;

		if (NumLines(middle) < N)
			maxLen = middle;
		else
			minLen = middle + 1;
	}

	cout << maxLen - 1 << "\n";
	return 0;
}
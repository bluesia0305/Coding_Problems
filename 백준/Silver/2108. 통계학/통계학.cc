#include <iostream>
#include <algorithm>
#include <cmath>

#define RANGE 4000

using namespace std;

int Nums[500000];
int Freq[2 * RANGE + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Nums[i];
		Sum += Nums[i];
		Freq[Nums[i] + RANGE]++;
	}

	sort(Nums, Nums + N);

	int idx = -1;
	int maxFreq = 0;
	for (int i = 0; i < 2 * RANGE + 1; i++)
		if (maxFreq < Freq[i])
		{
			maxFreq = Freq[i];
			idx = i;
		}

	for (int i = idx + 1; i < 2 * RANGE + 1; i++)
		if (Freq[i] == maxFreq)
		{
			idx = i;
			break;
		}

	int Avg = round((float)Sum / N);
	cout
		<< Avg << "\n"
		<< Nums[(N - 1) / 2] << "\n"
		<< idx - RANGE << "\n"
		<< Nums[N - 1] - Nums[0] << "\n";

	return 0;
}
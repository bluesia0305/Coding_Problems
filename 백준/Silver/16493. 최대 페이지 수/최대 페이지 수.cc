#include <iostream>
#include <algorithm>

using namespace std;

struct Chapter
{
	int Days;
	int Pages;
};

Chapter Chapters[20];
int DP[201];

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> Chapters[i].Days >> Chapters[i].Pages;

	for (int i = 0; i < M; i++)
		for (int m = N; m >= Chapters[i].Days; m--)
			if (m == Chapters[i].Days || DP[m - Chapters[i].Days] > 0)
			{
				int valueSum = DP[m - Chapters[i].Days] + Chapters[i].Pages;
				if (DP[m] < valueSum)
					DP[m] = valueSum;
			}

	cout << *max_element(DP, DP + N + 1) << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int Points[1002];
int N, M, L;

bool Cuttable(int len, int count)
{
	int cnt = 0;
	int start = 0;
	for (int i = 0; i <= M + 1; i++)
	{
		if (Points[i] - Points[start] >= len)
		{
			cnt++;
			start = i;
		}
	}

	return cnt >= count;
}

int BinarySearch(int left, int right, int count)
{
	while (left < right)
	{
		int len = (left + right) / 2;
		if (Cuttable(len, count))
			left = len + 1;
		else
			right = len;
	}

	return right - 1;
}

int main()
{
	cin >> N >> M >> L;

	Points[M + 1] = L;
	for (int i = 1; i <= M; i++)
		cin >> Points[i];

	while (N--)
	{
		int CutCount;
		cin >> CutCount;
		cout << BinarySearch(0, L + 1, CutCount + 1) << "\n";
	}
	
	return 0;
}
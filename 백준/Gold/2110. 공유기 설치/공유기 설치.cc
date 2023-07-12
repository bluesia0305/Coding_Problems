#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int Houses[200000];

bool CanInstall(int c, int interval)
{
	int start = Houses[0];
	c--;

	for (int house : Houses)
	{
		if (house - start < interval)
			continue;
		
		start = house;
		if (--c == 0)
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> Houses[i];
	
	sort(Houses, Houses + N);

	int Min = 1;
	int Max = Houses[N - 1] - Houses[0] + 1;

	while (Min < Max)
	{
		int middle = (Min + Max) / 2;
		if (CanInstall(C, middle))
			Min = middle + 1;
		else
			Max = middle;
	}

	cout << Max - 1 << "\n";
	return 0;
}
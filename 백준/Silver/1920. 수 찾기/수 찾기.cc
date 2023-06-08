#include <iostream>
#include <algorithm>

using namespace std;

int Numbers[100000];

void BinarySearch(int num, int left, int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (num == Numbers[middle])
		{
			cout << "1\n";
			return;
		}

		if (num < Numbers[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}

	cout << "0\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Numbers[i];

	sort(&Numbers[0], &Numbers[N]);

	int M;
	cin >> M;
	while (M--)
	{
		int num;
		cin >> num;
		BinarySearch(num, 0, N - 1);
	}

	return 0;
}
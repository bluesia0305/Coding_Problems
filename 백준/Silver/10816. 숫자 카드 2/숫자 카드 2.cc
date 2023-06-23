#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Cards[500000];

int SearchLeft(int num)
{
	int left = 0, right = N;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (num > Cards[middle])
			left = middle + 1;
		else
			right = middle;
	}

	return right;
}

int SearchRight(int num)
{
	int left = 0, right = N;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (num < Cards[middle])
			right = middle;
		else
			left = middle + 1;
	}

	return left;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Cards[i];

	sort(&Cards[0], &Cards[N - 1] + 1);

	int M;
	cin >> M;
	while (M--)
	{
		int card;
		cin >> card;
		cout << SearchRight(card) - SearchLeft(card) << " ";
	}
	cout << "\n";

	return 0;
}
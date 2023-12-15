#include <iostream>
using namespace std;

bool marbles[40001];

int main()
{
	int n;
	cin >> n;

	marbles[0] = true;
	int sum = 0;
	while (n--)
	{
		int w;
		cin >> w;

		sum += w;
		for (int i = sum; i >= 0; i--)
			if (marbles[i])
				marbles[i + w] = true;

		for (int i = 0; i <= sum; i++)
			if (marbles[i])
				marbles[w - i >= 0 ? w - i : i - w] = true;
	}

	int m;
	cin >> m;
	while (m--)
	{
		int marble;
		cin >> marble;
		cout << (marbles[marble] ? "Y" : "N") << " ";
	}

	cout << "\n";
	return 0;
}
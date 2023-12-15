#include <iostream>

using namespace std;

bool marbles[31][40001];

int main()
{
	int n;
	cin >> n;
	
	marbles[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		int weight;
		cin >> weight;

		for (int j = 0; j < 40001; j++)
		{
			if (marbles[i - 1][j])
			{
				marbles[i][j] = true;
				marbles[i][j + weight] = true;
				marbles[i][weight - j >= 0 ? weight - j : j - weight] = true;
			}
		}
	}

	int m;
	cin >> m;
	while (m--)
	{
		int marble;
		cin >> marble;
		cout << (marbles[n][marble] ? "Y" : "N") << " ";
	}

	cout << "\n";
	return 0;
}
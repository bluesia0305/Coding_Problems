#include <iostream>

using namespace std;

int N;
bool Pattern[2487][2487];

void MakePattern(int x, int y, int n)
{
	int len = n / 3;
	for (int i = y; i < y + n; i += len)
		for (int j = x; j < x + n; j += len)
		{
			if (!(i == y + len && j == x + len))
			{
				if (len > 1)
					MakePattern(j, i, len);
				else
					Pattern[i][j] = true;
			}
		}
}

void PrintStar()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << (Pattern[i][j] ? "*" : " ");
		
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	MakePattern(0, 0, N);
	PrintStar();
	return 0;
}
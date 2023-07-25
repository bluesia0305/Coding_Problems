#include <iostream>

using namespace std;

int D[100][100];

int main()
{
	int N, M;
	cin >> N >> M;

	while (M--)
	{
		int from, dest, cost;
		cin >> from >> dest >> cost;

		if (D[from - 1][dest - 1])
			D[from - 1][dest - 1] = cost < D[from - 1][dest - 1] ? cost : D[from - 1][dest - 1];
		else
			D[from - 1][dest - 1] = cost;
	}

	for (int w = 0; w < N; w++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (i == j || w == i || w == j)
					continue;

				if (D[i][w] && D[w][j])
					if (!D[i][j] || 
						D[i][j] > D[i][w] + D[w][j])
						D[i][j] = D[i][w] + D[w][j];
			}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << D[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
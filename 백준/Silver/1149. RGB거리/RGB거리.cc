#include <iostream>
#include <algorithm>

using namespace std;

int Costs[1000][3];

int main()
{
	int N, Cost = 0;
	cin >> N;

	int R, G, B;
	cin >> Costs[0][0] >> Costs[0][1] >> Costs[0][2];

	int costs[3] = { 0, };
	for (int i = 1; i < N; i++)
	{
		cin >> costs[0] >> costs[1] >> costs[2];
		
		for (int j = 0; j < 3; j++)
		{
			int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;
			Costs[i][j] = costs[j] + (Costs[i - 1][idx1] < Costs[i - 1][idx2] ? Costs[i - 1][idx1] : Costs[i - 1][idx2]);
		}
	}

	cout << *min_element(&Costs[N - 1][0], &Costs[N - 1][2] + 1) << "\n";
	return 0;
}
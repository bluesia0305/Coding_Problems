#include <iostream>

using namespace std;

int N;
int Cities[100000];
int Edges[99999];
size_t Cost;

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> Edges[i];

	for (int i = 0; i < N; i++)
		cin >> Cities[i];

	int i = 0;
	while (i < N - 1)
	{
		size_t oilCost = Cities[i];
		size_t distSum = 0;

		while (oilCost <= Cities[i])
		{
			distSum += Edges[i];
			i++;
		}

		Cost += distSum * oilCost;
	}

	cout << Cost << "\n";
	return 0;
}
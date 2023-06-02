#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, Total[3] = { 0, }, Subtotal[3] = { 0, };
	cin >> N;

	int R, G, B;
	cin >> Subtotal[0] >> Subtotal[1] >> Subtotal[2];

	int costs[3] = { 0, };
	for (int i = 1; i < N; i++)
	{
		cin >> costs[0] >> costs[1] >> costs[2];
		
		for (int j = 0; j < 3; j++)
		{
			int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;
			Total[j] = costs[j] + (Subtotal[idx1] < Subtotal[idx2] ? Subtotal[idx1] : Subtotal[idx2]);
		}

		for (int j = 0; j < 3; j++)
			Subtotal[j] = Total[j];
	}

	cout << *min_element(&Total[0], &Total[2] + 1) << "\n";
	return 0;
}
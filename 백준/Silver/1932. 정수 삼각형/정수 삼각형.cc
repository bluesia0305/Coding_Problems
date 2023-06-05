#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int max = 0;
	int Nums[500] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			int num;
			cin >> num;
			if (j == 0)
				Nums[j] += num;
			else if (j == i)
				Nums[j] = Nums[j - 1] + num;
			else
				Nums[j] = num + (Nums[j - 1] > Nums[j] ? Nums[j - 1] : Nums[j]);

			max = max < Nums[j] ? Nums[j] : max;
		}
	}

	cout << max << "\n";

	return 0;
}
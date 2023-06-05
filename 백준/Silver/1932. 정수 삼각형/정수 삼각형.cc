#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int Nums[500][500];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> Nums[i][j];

	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			Nums[i - 1][j] = Nums[i - 1][j] + (Nums[i][j] > Nums[i][j + 1] ? Nums[i][j] : Nums[i][j + 1]);

	cout << Nums[0][0];

	return 0;
}
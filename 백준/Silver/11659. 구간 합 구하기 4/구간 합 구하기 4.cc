#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> Nums(N);
	vector<int> FwdTab(N);
	vector<int> BwdTab(N);
	for (int i = 0; i < N; i++)
		cin >> Nums[i];

	FwdTab[0] = Nums[0];
	BwdTab[N - 1] = Nums[N - 1];
	for (int i = 1; i < N; i++)
	{
		FwdTab[i] = FwdTab[i - 1] + Nums[i];
		BwdTab[N - 1 - i] = BwdTab[N - i] + Nums[N - 1 - i];
	}
	
	while (M--)
	{
		int i, j;
		cin >> i >> j;
	
		int Sum = FwdTab[N - 1];
		if (i > 1)
			Sum -= FwdTab[i - 2];
		if (j < N)
			Sum -= BwdTab[j];
	
		cout << Sum << "\n";
	}
	
	return 0;
}
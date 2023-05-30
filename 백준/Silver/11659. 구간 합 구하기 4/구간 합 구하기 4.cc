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

	vector<int> FwdTab(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		FwdTab[i] = (i ? FwdTab[i - 1] : 0) + num;
	}
	
	while (M--)
	{
		int i, j;
		cin >> i >> j;

		cout << FwdTab[j - 1] - (i > 1 ? FwdTab[i - 2] : 0) << "\n";
	}
	
	return 0;
}
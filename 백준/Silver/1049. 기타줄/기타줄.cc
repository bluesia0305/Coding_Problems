#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Package;
vector<int> Each;

int main()
{
	int N, M, cost;
	cin >> N >> M;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		Package.push_back(a);
		Each.push_back(b);
	}

	sort(Package.begin(), Package.end());
	sort(Each.begin(), Each.end());

	if (Package[0] < Each[0] * 6)
		cost = Package[0] * (N / 6);
	else
		cost = Each[0] * (N - N % 6);

	if (Package[0] < Each[0] * (N % 6))
		cost += Package[0];
	else
		cost += Each[0] * (N % 6);

	cout << cost << "\n";
	return 0;
}
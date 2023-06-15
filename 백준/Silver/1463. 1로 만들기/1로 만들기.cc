#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int OpCounts[1000001];

int GetCount(int n)
{
	if (n > 1)
	{
		vector<int> results;

		if (!(n % 3))
			results.push_back((OpCounts[n / 3] ? OpCounts[n / 3] : GetCount(n / 3)) + 1);

		if (!(n % 2))
			results.push_back((OpCounts[n / 2] ? OpCounts[n / 2] : GetCount(n / 2)) + 1);

		results.push_back((OpCounts[n - 1] ? OpCounts[n - 1] : GetCount(n - 1)) + 1);
		return OpCounts[n] = *min_element(results.begin(), results.end());
	}

	return 0;
}

int main()
{
	int N;
	cin >> N;
	cout << GetCount(N) << "\n";
	return 0;
}
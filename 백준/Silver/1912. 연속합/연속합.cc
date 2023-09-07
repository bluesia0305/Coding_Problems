#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, max, memoize;
	cin >> n >> k;
	max = memoize = k;
	n--;

	while (n--)
	{
		cin >> k;
		if (max < k)
			max = k;

		if (memoize + k > 0)
		{
			memoize += k;
			if (max < memoize)
				max = memoize;
		}
		else
			memoize = 0;
	}

	cout << max << "\n";

	return 0;
}
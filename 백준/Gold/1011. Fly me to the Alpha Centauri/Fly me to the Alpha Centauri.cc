#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int x, y, ans = 0;
		cin >> x >> y;

		int d = y - x;
		int n = sqrt(d);
		if (d == n * n)
			ans = 2 * n - 1;
		else if (d <= n * n + n)
			ans = 2 * n;
		else
			ans = 2 * n + 1;
		
		cout << ans << "\n";
	}

	return 0;
}
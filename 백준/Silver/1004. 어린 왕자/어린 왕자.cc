#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int N, count = 0;
		cin >> N;

		while (N--)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;

			int dx1 = cx - x1;
			int dy1 = cy - y1;
			int dx2 = cx - x2;
			int dy2 = cy - y2;
			if ((dx1 * dx1 + dy1 * dy1 < r * r) ^
				(dx2 * dx2 + dy2 * dy2 < r * r))
				count++;
		}

		cout << count << "\n";
	}
}
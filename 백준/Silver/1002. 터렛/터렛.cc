#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int T;
	int x1, x2, y1, y2, r1, r2;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		double rdiff = r1 > r2 ? r1 - r2 : r2 - r1;
		double rsum = r1 + r2;

		if (x1 == x2 && y1 == y2 && r1 == r2)
			printf("-1\n");
		else if (d < rdiff || d > rsum)
			printf("0\n");
		else if(d == rdiff || d == rsum)
			printf("1\n");
		else
			printf("2\n");
	}

	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	
	int det = a * e - b * d;
	printf("%d %d\n", (c * e - b * f) / det, (a * f - c * d) / det);

	return 0;
}
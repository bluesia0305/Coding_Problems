#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int N;
	int start;
	int next;
	int temp;

	scanf("%d", &N);
	scanf("%d", &start);
	scanf("%d", &next);

	int gcd_dist = next - start;
	for (int i = 2; i < N; i++)
	{
		scanf("%d", &temp);
		gcd_dist = GCD(temp - next, gcd_dist);
		next = temp;
	}
	
	printf("%d\n", (next - start) / gcd_dist + 1 - N);

	return 0;
}
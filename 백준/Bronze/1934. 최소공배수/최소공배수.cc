#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	return b ? GCD(b, a % b) : a;
}

int main()
{
	int T, A, B;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A * B / GCD(A, B));
	}

	return 0;
}
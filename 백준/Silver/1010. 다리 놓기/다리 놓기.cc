#include <iostream>

int main()
{
	// 분자/분모 pairing을 통한 팩토리얼 계산
	int T, N, M;
	unsigned long long prod;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);
	
		if (M - N < N)
			N = M - N;

		prod = 1;
		for (int j = 0; j < N; j++)
		{
			prod *= M - j;
			prod /= j + 1;
		}

		printf("%lld\n", prod);
	}
}
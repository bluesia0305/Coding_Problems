// Problem #002: 피보나치 수열에서 4백만 이하이면서 짝수인 항의 합?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int sum = 0;
	int f_1 = 1;
	int f_2 = 1;

	while (true)
	{
		int f_3 = f_1 + f_2;
		if (f_3 > 4000000) break;
		if (!(f_3 % 2)) sum += f_3;
		f_1 = f_2;
		f_2 = f_3;
	}

	printf("답: %i\n", sum);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
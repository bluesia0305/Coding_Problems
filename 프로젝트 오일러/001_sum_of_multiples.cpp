// Problem #001: 1000보다 작은 자연수 중에서 3 또는 5의 배수를 모두 더하면?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int sum = 0;
	for (int i = 1; i < 1000; ++i)
		if (!(i % 3) || !(i % 5)) sum += i;

	printf("답: %i\n", sum);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
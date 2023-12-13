// Problem #006: 1부터 100까지 "제곱의 합"과 "합의 제곱"의 차는?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int sum_of_squares = 0;
	int square_of_sum = 0;

	for (int i = 1; i <= 100; ++i)
	{
		sum_of_squares += i * i;
		square_of_sum += i;
	}
	square_of_sum *= square_of_sum;
	printf("제곱의 합: %i\n", sum_of_squares);
	printf("합의 제곱: %i\n", square_of_sum);
	printf("\n");

	if (square_of_sum - sum_of_squares) printf("답: %i\n", square_of_sum - sum_of_squares);
	else printf("답: %i\n", sum_of_squares - square_of_sum);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
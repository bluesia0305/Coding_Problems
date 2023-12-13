#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

int GetProperFactorsSum(int num)
{
	std::vector<int> factors;
	for (int i = 1; i <= sqrt(num); ++i)
	{
		if (!(num % i))
		{
			factors.push_back(i);
			factors.push_back(num / i);
		}
	}

	int sum = 0;
	for (auto iter = factors.begin(); iter != factors.end(); ++iter)
	{ if (*iter != num) sum += *iter; }

	return sum;
}

int main()
{
	clock_t start, end;
	start = clock();

	int sum_amicables = 0;
	//// 함수 정상 작동여부 테스트.
	//printf("%i %i\n", 220, GetProperFactorsSum(284));
	//printf("%i %i\n", 284, GetProperFactorsSum(220));
	for (int num = 1; num <= 10000; ++num)
	{
		int sum_factors = GetProperFactorsSum(num);
		if (sum_factors != num && GetProperFactorsSum(sum_factors) == num)
		{
			sum_amicables += num;
		}
	}
	printf("답: %i\n", sum_amicables);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
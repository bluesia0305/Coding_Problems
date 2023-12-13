// Problem #014: 백만 이하로 시작하는 우박수 중 가장 긴 과정을 거치는 것은?

#include <iostream>
#include <ctime>
#include <map>

void print_hailstone(long long num)
{	
	long long i = 1;
	while (true)
	{
		printf("%lld ", num);
		if (num <= 1) break;
		else
		{
			printf("-> ");
			if (!(num % 2)) num = num / 2;
			else num = 3 * num + 1;
			++i;
		}
	}
	printf("\n");
}

int main()
{
	clock_t start, end;
	start = clock();

	const int N = 1000000;

	// key: 숫자, value: 우박수열 과정 수 의 pair를 갖는 map container를 이용.
	std::map<long long, int> hailstone_numbers;
	hailstone_numbers.insert(std::pair<long long, int>(1, 1));

	for (long long i = 1; i <= N; ++i)
	{
		long long num = i;
		// 0에서 시작해서, 특정 동작을 수행할 때마다 order를 증가연산해야 제대로 계산됨.
		int hailstone_order = 0;
		if (!(i % 100000)) printf("자연수 %lld 의 우박수열 탐색 중...\n", num);
		while (true)
		{
			if (num == 1)
			{
				++hailstone_order;
				break;
			}
			else
			{
				// 이 부분이 연산 단축에 핵심(이미 계산된 숫자에 대한 재계산 방지)
				auto iter = hailstone_numbers.find(num);
				if (iter != hailstone_numbers.end())
				{
					hailstone_order += iter->second;
					break;
				}
				else
				{
					if (!(num % 2)) num /= 2;
					else num = 3 * num + 1;
					++hailstone_order;
				}
			}
		}
		hailstone_numbers.insert(std::pair<long long, int>(i, hailstone_order));
	}

	long long max_hailstone_num = 1;
	int max_hailstone_order = 1;
	auto iter = hailstone_numbers.begin();
	for (; iter != hailstone_numbers.end(); ++iter)
	{
		if (iter->second > max_hailstone_order)
		{
			max_hailstone_num = iter->first;
			max_hailstone_order = iter->second;
		}
	}

	printf("답: %lld (우박수열 과정 %i 회)\n", max_hailstone_num, max_hailstone_order);
	print_hailstone(max_hailstone_num);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
// Problem #023: �� ���׼��� ������ ��Ÿ�� �� ���� ��� ���� ������ ����?

#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#define UPPER_BOUND 28123

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
	{
		if (*iter != num) sum += *iter;
	}

	return sum;
}

int main()
{
	clock_t start, end;
	start = clock();
	std::vector<bool> abundant_numbers;
	long long sum = 0;

	for (int i = 1; i < UPPER_BOUND; ++i)
	{
		if (i < GetProperFactorsSum(i)) abundant_numbers.push_back(i);
		for ()
	}




	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
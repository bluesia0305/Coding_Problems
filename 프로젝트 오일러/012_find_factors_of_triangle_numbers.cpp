// Problem #012: 500개 이상의 약수를 갖는 가장 작은 삼각수는?

#include <iostream>
#include <ctime>
#include <cmath>
#include <map>

//void print_factors(int i, int num, std::map<int, int> factor)
//{
//	printf("%i번째 삼각수 %i: ", i, num);
//	auto iter = factor.begin();
//	for (; iter != factor.end(); ++iter)
//		printf("%i ", iter->first);
//	std::cout << "(" << factor.size() << " 개)" << std::endl;
//}

int num_factors(int num)
{
	int factors = 2;

	for (int div = 2; div <= (int)sqrt(num); ++div)
	{
		if (!(num % div))
		{
			if (num != num % div) factors += 2;
			else ++factors;
		}
	}

	return factors;
}

int main()
{
	clock_t start, end;
	start = clock();

	int n = 1;
	int triangleNum = 0;

	//std::map<int, int> factor;
	//
	//while (true)
	//{
	//	triangleNum += n;
	//
	//	for (int div = 1; div <= (int)sqrt(triangleNum); ++div)
	//	{
	//		if (!(triangleNum % div))
	//		{
	//			factor.insert(std::pair<int, int>(div, triangleNum / div));
	//			factor.insert(std::pair<int, int>(triangleNum / div, div));
	//		}
	//	}
	//
	//	//if (!(n % 1000)) print_factors(i, triangleNum, factor);
	//	if (factor.size() >= 500)
	//	{
	//		print_factors(n, triangleNum, factor);
	//		printf("답: %i\n", triangleNum);
	//		break;
	//	}
	//	factor.clear();
	//	++n;
	//}

	//while (true)
	//{
	//	triangleNum = n * (n + 1) / 2;
	//	int temp = num_factors(triangleNum);
	//	if (temp >= 500)
	//	{
	//		printf("답: %i (약수의 개수: %i 개)\n", triangleNum, temp);
	//		break;
	//	}

	//	++n;
	//}

	// 삼각수가 등차수열의 합임을 이용하며,
	// 두 수의 곱으로 이루어진 수의 약수의 개수는 각각 곱하는 수의 약수의 개수의 곱임을 이용하는 방법.
	int num_factors1, num_factors2;

	while (true)
	{
		triangleNum = n * (n + 1) / 2;
		if (!(n % 2))
		{
			num_factors1 = num_factors(n / 2);
			num_factors2 = num_factors(n + 1);
		}
		else
		{
			num_factors1 = num_factors(n);
			num_factors2 = num_factors((n + 1) / 2);
		}

		if (num_factors1 * num_factors2 >= 500)
		{
			printf("답: %i (약수의 개수: %i 개)\n", triangleNum, num_factors1 * num_factors2);
			break;
		}

		++n;
	}

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
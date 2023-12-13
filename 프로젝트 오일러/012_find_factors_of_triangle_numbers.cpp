// Problem #012: 500�� �̻��� ����� ���� ���� ���� �ﰢ����?

#include <iostream>
#include <ctime>
#include <cmath>
#include <map>

//void print_factors(int i, int num, std::map<int, int> factor)
//{
//	printf("%i��° �ﰢ�� %i: ", i, num);
//	auto iter = factor.begin();
//	for (; iter != factor.end(); ++iter)
//		printf("%i ", iter->first);
//	std::cout << "(" << factor.size() << " ��)" << std::endl;
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
	//		printf("��: %i\n", triangleNum);
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
	//		printf("��: %i (����� ����: %i ��)\n", triangleNum, temp);
	//		break;
	//	}

	//	++n;
	//}

	// �ﰢ���� ���������� ������ �̿��ϸ�,
	// �� ���� ������ �̷���� ���� ����� ������ ���� ���ϴ� ���� ����� ������ ������ �̿��ϴ� ���.
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
			printf("��: %i (����� ����: %i ��)\n", triangleNum, num_factors1 * num_factors2);
			break;
		}

		++n;
	}

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
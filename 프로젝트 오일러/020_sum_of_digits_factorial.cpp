// Problem #020: 100!�� �ڸ����� ��� ���ϸ�?

#include <iostream>
#include <ctime>
#include <vector>
#define VIRTUAL_DIGITS 100
typedef unsigned short VAR_TYPE;

void printVector(std::vector<VAR_TYPE> vector)
{
	auto iter = vector.begin();
	for (; iter != vector.end(); ++iter)
	{ printf("%d", *iter); }
	printf("\n");
}

std::vector<VAR_TYPE> multiply_array(std::vector<VAR_TYPE> large_num, int num)
{
	std::vector<VAR_TYPE> result;
	for (int i = 0; i < VIRTUAL_DIGITS; ++i)
	{ result.push_back(0); }

	auto iter = large_num.begin();
	for (; iter != large_num.end(); ++iter)
	{ result.push_back((*iter) * num); }

	for (int i = result.size() - 1; i > 1; --i)
	{
		if (result[i])
		{
			result[i - 1] += result[i] / 10;
			result[i] %= 10;
		}
	}

	for (int i = 0; i < VIRTUAL_DIGITS; ++i)
	{ if (!result[0]) result.erase(result.begin()); }

	return result;
}

int main()
{
	clock_t start, end;
	start = clock();

	unsigned num = 100;					// �� ���丮���� �������? �� ����
	std::vector<VAR_TYPE> result;		// ���丮�� ��갪�� ������ ����.
	result.push_back(1);				// result == 1! ���� ����.

	for (int i = 2; i <= num; ++i)
	{ result = multiply_array(result, i); }

	// ����� result ���� ���.
	printf("%i ! = ", num);
	printVector(result);

	int sum = 0;
	auto iter = result.begin();
	for (; iter != result.end(); ++iter)
	{ sum += *iter; }
	printf("\n");

	printf("��: %d\n", sum);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
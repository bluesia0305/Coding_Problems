// Problem #016: 2^1000�� �� �ڸ����� ��� ���ϸ�?

#include <iostream>
#include <ctime>
#include <cmath>

void multiply_two(unsigned* const arr, unsigned const length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] *= 2;

		if (arr[i] >= 10)
		{
			arr[i - 1]++;
			arr[i] %= 10;
		}		
	}
}

int sum_digits(unsigned* const arr, unsigned const length, bool print = false)
{
	unsigned sum = 0;
	bool ifzero = true;
	
	for (int i = 0; i < length; i++)
	{
		if (arr[i]) ifzero = false;
		if (!ifzero)
		{
			if (print) printf("%u", arr[i]);
			sum += arr[i];
		}
	}
	if (print) printf("\n");

	return sum;
}

int main()
{
	clock_t start, end;
	start = clock();

	unsigned const exponent = 1000;
	unsigned const length = exponent * log10(2) + 1;	// 2^(exponent)�� ���ڸ��� ������ ���ϴ� ��
	printf("2�� %u������ %u�ڸ��� ���Դϴ�\n", exponent, length);

	unsigned* pArr = new unsigned[length];	// 2�� �ŵ������� �迭�� ��Ÿ���� ���� �����迭�� �Ҵ�

	for (int i = 0; i < length - 1; i++) { pArr[i] = 0; }
	pArr[length - 1] = 1;					// arr = { 0, 0, 0, ..., 0, 1 }; �� �ʱ�ȭ

	for (int i = 0; i < exponent; i++) { multiply_two(pArr, length); }
	printf("2�� %u������ ��� �ڸ����� ����: %u\n", exponent, sum_digits(pArr, length));
	
	delete[] pArr;
	pArr = nullptr;

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
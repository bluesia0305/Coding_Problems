// Problem #016: 2^1000의 각 자릿수를 모두 더하면?

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
	unsigned const length = exponent * log10(2) + 1;	// 2^(exponent)가 몇자리의 수인지 구하는 식
	printf("2의 %u제곱은 %u자리의 수입니다\n", exponent, length);

	unsigned* pArr = new unsigned[length];	// 2의 거듭제곱을 배열로 나타내기 위해 동적배열을 할당

	for (int i = 0; i < length - 1; i++) { pArr[i] = 0; }
	pArr[length - 1] = 1;					// arr = { 0, 0, 0, ..., 0, 1 }; 로 초기화

	for (int i = 0; i < exponent; i++) { multiply_two(pArr, length); }
	printf("2의 %u제곱의 모든 자릿수의 총합: %u\n", exponent, sum_digits(pArr, length));
	
	delete[] pArr;
	pArr = nullptr;

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
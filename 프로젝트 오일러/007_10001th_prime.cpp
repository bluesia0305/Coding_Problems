// Problem #007: 10001��°�� �Ҽ�

#include <iostream>
#include <ctime>
#include <cmath>

bool isPrime(long long num)
{
	if (num == 2) return true;
	if (num == 1) return false;
	if (!(num % 2)) return false;

	for (long long i = 3; i <= (int)sqrt(num); i += 2)
		if (!(num % i)) return false;

	return true;
}

int main()
{
	clock_t start, end;
	start = clock();

	long long num = 2;
	int count = 0;
	while (true)
	{
		if (isPrime(num)) ++count;
		if (count == 10001) break;
		else ++num;
	}

	printf("��: %lld\n", num);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
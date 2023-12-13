// Problem #003: 600851475143의 소인수 중에서 가장 큰 수?

#include <iostream>
#include <ctime>
#include <cmath>


bool isPrime(int num)
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

	long long num = 600851475143;
	long long biggest_prime_factor = 2;

	long long factor = 2;
	while (true)
	{
		if (!(num % factor))
		{
			printf("factor: %lld\t", factor);
			if (isPrime(factor)) printf("(prime)\n");
			else printf("\n");
			
			if (factor > biggest_prime_factor) biggest_prime_factor = factor;
			
			if (num / factor == 1) break;
			else num = num / factor;
			
			factor = 2;
		}
		else factor++;
	}

	printf("답: %lld\n", biggest_prime_factor);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
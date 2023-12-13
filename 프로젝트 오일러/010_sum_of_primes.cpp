// Problem #000: 

#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

// 소수 판별을 직접적으로 하는 것은 알고리즘을 잘 짜더라도 연산을 많이 필요로 한다.
//bool isPrime(long long num)
//{
//	if (num == 2) return true;
//	if (num == 1) return false;
//	if (!(num % 2)) return false;
//
//	for (long long i = 3; i <= (int)sqrt(num); i += 2)
//		if (!(num % i)) return false;
//
//	return true;
//}

int main()
{
	clock_t start, end;
	start = clock();

	//for (long long i = 2; i <= 2000000; ++i)
	//{
	//	if (isPrime(i))
	//	{
	//		printf("%lld\n", i);
	//		sum += i;
	//	}
	//}


	// '에라토스테네스의 체'를 이용한 방법.
	int N = 2000000;
	long long sum = 0;
	std::vector<bool> sieve(N + 1);		// 기본값 = 0 (즉, false가 default value임)

	for (int i = 2; i <= N; ++i)
	{
		if (sieve[i] == false) sum += i;
		for (int j = i; j <= N; j += i) // 체에서 배수를 모두 거둔다.
			sieve[j] = true;
	}

	printf("답: %lld\n", sum);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
// Problem #005: 1 ~ 20 사이의 어떤 수로도 나누어 떨어지는 가장 작은 수?

#include <iostream>
#include <ctime>

//bool hasFactors1to20(int num)
//{
//	for (int i = 1; i <= 20; ++i)
//		if (num % i) return false;
//	
//	return true;
//}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{ return b? gcd(b, a % b) : a; }

unsigned long long lcm(unsigned long long a, unsigned long long b)
{ return (a * b / gcd(a, b)); }
	
int main()
{
	clock_t start, end;
	start = clock();

	//int num = 20;
	//while (true)
	//{
	//	if (hasFactors1to20(num)) break;
	//	if (!(num % 10000000)) printf("%-9i 까지의 수 중에서 조건을 만족하는 수가 존재하지 않습니다.\n", num);
	//	num++;
	//}
	//
	//printf("답: %i\n", num);
	

	// 최대공약수를 쉽게 구하는 수학적 테크닉 활용방법.
	// : 주어진 두 수에 대한 최대공약수, 최소공배수를 이용.
	//   또한 lcm(a, b, c) = lcm(lcm(a, b), c) 과 같이 재귀적으로 계산이 가능함을 이용한다.
	unsigned long long result = lcm(1, 2);
	for (unsigned long long i = 3; i <= 20; ++i)
		result = lcm(result, i);

	printf("답: %lld\n", result);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
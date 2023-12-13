// Problem #000: 

#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

// �Ҽ� �Ǻ��� ���������� �ϴ� ���� �˰����� �� ¥���� ������ ���� �ʿ�� �Ѵ�.
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


	// '�����佺�׳׽��� ü'�� �̿��� ���.
	int N = 2000000;
	long long sum = 0;
	std::vector<bool> sieve(N + 1);		// �⺻�� = 0 (��, false�� default value��)

	for (int i = 2; i <= N; ++i)
	{
		if (sieve[i] == false) sum += i;
		for (int j = i; j <= N; j += i) // ü���� ����� ��� �ŵд�.
			sieve[j] = true;
	}

	printf("��: %lld\n", sum);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
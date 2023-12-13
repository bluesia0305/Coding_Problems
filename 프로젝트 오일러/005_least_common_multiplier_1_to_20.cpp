// Problem #005: 1 ~ 20 ������ � ���ε� ������ �������� ���� ���� ��?

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
	//	if (!(num % 10000000)) printf("%-9i ������ �� �߿��� ������ �����ϴ� ���� �������� �ʽ��ϴ�.\n", num);
	//	num++;
	//}
	//
	//printf("��: %i\n", num);
	

	// �ִ������� ���� ���ϴ� ������ ��ũ�� Ȱ����.
	// : �־��� �� ���� ���� �ִ�����, �ּҰ������ �̿�.
	//   ���� lcm(a, b, c) = lcm(lcm(a, b), c) �� ���� ��������� ����� �������� �̿��Ѵ�.
	unsigned long long result = lcm(1, 2);
	for (unsigned long long i = 3; i <= 20; ++i)
		result = lcm(result, i);

	printf("��: %lld\n", result);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
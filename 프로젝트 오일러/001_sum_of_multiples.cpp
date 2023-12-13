// Problem #001: 1000���� ���� �ڿ��� �߿��� 3 �Ǵ� 5�� ����� ��� ���ϸ�?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int sum = 0;
	for (int i = 1; i < 1000; ++i)
		if (!(i % 3) || !(i % 5)) sum += i;

	printf("��: %i\n", sum);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
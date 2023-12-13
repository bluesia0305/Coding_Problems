// Problem #006: 1���� 100���� "������ ��"�� "���� ����"�� ����?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int sum_of_squares = 0;
	int square_of_sum = 0;

	for (int i = 1; i <= 100; ++i)
	{
		sum_of_squares += i * i;
		square_of_sum += i;
	}
	square_of_sum *= square_of_sum;
	printf("������ ��: %i\n", sum_of_squares);
	printf("���� ����: %i\n", square_of_sum);
	printf("\n");

	if (square_of_sum - sum_of_squares) printf("��: %i\n", square_of_sum - sum_of_squares);
	else printf("��: %i\n", sum_of_squares - square_of_sum);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
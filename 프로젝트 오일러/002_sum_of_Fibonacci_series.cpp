// Problem #002: �Ǻ���ġ �������� 4�鸸 �����̸鼭 ¦���� ���� ��?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int sum = 0;
	int f_1 = 1;
	int f_2 = 1;

	while (true)
	{
		int f_3 = f_1 + f_2;
		if (f_3 > 4000000) break;
		if (!(f_3 % 2)) sum += f_3;
		f_1 = f_2;
		f_2 = f_3;
	}

	printf("��: %i\n", sum);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
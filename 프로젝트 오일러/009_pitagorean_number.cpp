// Problem #009: a + b + c = 1000 �� �Ǵ� ��Ÿ��� ��

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int a = 1;
	int b = 2;
	int c = 3;

	while (true)
	{
		b = a + 1;
		while (true)
		{
			c = 1000 - a - b;
			if (a * a + b * b == c * c) break;
			else if (b < c - 1) b++;
			else break;
		}
		if (a * a + b * b == c * c) break;
		else a++;
	}

	printf("��: %i (a = %i, b = %i, c = %i)\n", a * b * c, a, b, c);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
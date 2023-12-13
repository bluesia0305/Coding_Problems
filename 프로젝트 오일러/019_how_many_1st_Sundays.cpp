// Problem #019: 20���⿡��, �ſ� 1���� �Ͽ����� ���� �� ��?
// 
// ������ �޷¿� ���� �� ���� �Ϲ����� �����Դϴ�(�ʿ��� ��� �� �� ������ �� ���ŵ� �����ϴ�).
// 
// 1900�� 1�� 1���� �������̴�.
// 4��, 6��, 9��, 11���� 30�ϱ��� �ְ�, 1��, 3��, 5��, 7��, 8��, 10��, 12���� 31�ϱ��� �ִ�.
// 2���� 28��������, ���⿡�� 29�ϱ��� �ִ�.
// ������ ������ 4�� ������ �������� �ظ� ���Ѵ�.������ 400���� ������ �������� �ʴ� �� 100��°�� ������ �ƴϸ�, 400���� ������ �������� �����̴�
// 20����(1901�� 1�� 1�� ~2000�� 12�� 31��) ����, �ſ� 1���� �Ͽ����� ���� �� �� ���Դϱ� ?

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();

	int days = 0;
	int Sunday_of_1st = 0;
	for (int year = 1901; year <= 2000; ++year)
	{
		for (int month = 1; month <= 12; ++month)
		{
			switch (month)
			{
			case 1: case 3: case 5: case 7: case 8: case 10:
				days += 31;
				break;
			case 12:
				if (year < 2000) days += 31;
				break;
			case 4: case 6: case 9: case 11:
				days += 30;
				break;
			case 2:
				if ((!(year % 4) && (year % 100)) || (year % 400)) days += 29;
				else days += 28;
				break;
			}

			if (days % 7 == 6)
			{
				if (year != 2000 || month != 12)
				{
					printf("%i�� %2i�� 1���� �Ͽ��� �Դϴ�.\n", year, month);
					++Sunday_of_1st;
				}
			}
		}
	}
	printf("\n");

	printf("��: %i ��\n", Sunday_of_1st);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
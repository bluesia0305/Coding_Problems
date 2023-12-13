// Problem #019: 20세기에서, 매월 1일이 일요일인 경우는 몇 번?
// 
// 다음은 달력에 관한 몇 가지 일반적인 정보입니다(필요한 경우 좀 더 연구를 해 보셔도 좋습니다).
// 
// 1900년 1월 1일은 월요일이다.
// 4월, 6월, 9월, 11월은 30일까지 있고, 1월, 3월, 5월, 7월, 8월, 10월, 12월은 31일까지 있다.
// 2월은 28일이지만, 윤년에는 29일까지 있다.
// 윤년은 연도를 4로 나누어 떨어지는 해를 말한다.하지만 400으로 나누어 떨어지지 않는 매 100년째는 윤년이 아니며, 400으로 나누어 떨어지면 윤년이다
// 20세기(1901년 1월 1일 ~2000년 12월 31일) 에서, 매월 1일이 일요일인 경우는 총 몇 번입니까 ?

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
					printf("%i년 %2i월 1일은 일요일 입니다.\n", year, month);
					++Sunday_of_1st;
				}
			}
		}
	}
	printf("\n");

	printf("답: %i 번\n", Sunday_of_1st);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
// Problem #017: 1부터 1000까지 영어로 썼을 때 사용된 글자의 개수는?

#include <iostream>
#include <ctime>
#include <string>

int main()
{
	clock_t start, end;
	start = clock();

	std::string Hundred = "hundred";
	std::string And = "and";

	int num_chars = 0;
	std::string num_str;
	for (int i = 1; i <= 999; ++i)
	{
		int num_chars_temp = 0;
		num_str = std::to_string(i);
		if (num_str.length() == 1) num_str = "00" + num_str;
		else if (num_str.length() == 2)	num_str = "0" + num_str;

		std::cout << num_str;
		char digit1_int = num_str[0] - '0';
		char digit2_int = num_str[1] - '0';
		char digit3_int = num_str[2] - '0';

		if (digit1_int)
		{
			switch (digit1_int)
			{
			case 1: case 2: case 6:
				num_chars_temp += 3;
				break;
			case 3: case 7: case 8:
				num_chars_temp += 5;
				break;
			case 4: case 5: case 9:
				num_chars_temp += 4;
				break;
			}
			num_chars_temp += Hundred.length();
			if (digit2_int || digit3_int) num_chars_temp += And.length();
		}
		
		if (digit2_int == 1)
		{
			switch (digit3_int)
			{
			case 0:
				num_chars_temp += 3;
				break;
			case 1: case 2:
				num_chars_temp += 6;
				break;
			case 3: case 4: case 8: case 9:
				num_chars_temp += 8;
				break;
			case 5: case 6:
				num_chars_temp += 7;
				break;
			case 7:
				num_chars_temp += 9;
				break;
			}
		}
		else
		{
			switch (digit2_int)
			{
			case 2: case 3: case 8: case 9:
				num_chars_temp += 6;
				break;
			case 4: case 5: case 6:
				num_chars_temp += 5;
				break;
			case 7:
				num_chars_temp += 7;
				break;
			}

			switch (digit3_int)
			{
			case 1: case 2: case 6:
				num_chars_temp += 3;
				break;
			case 4: case 5: case 9:
				num_chars_temp += 4;
				break;
			case 3: case 7: case 8:
				num_chars_temp += 5;
				break;
			}
		}
		//std::cout << ": " << num_chars_temp << " 글자" << std::endl;
		num_chars += num_chars_temp;
	}
	num_chars += 11;		// one thousand

	printf("답: %i\n", num_chars);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
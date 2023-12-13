// Problem #004: 세 자리 수를 곱해 만들 수 있는 가장 큰 대칭수?

#include <iostream>
#include <ctime>
#include <string>

bool isPalindrome(int num)
{
	std::string str = std::to_string(num);
    for (unsigned i = 0; i < str.length() / 2; ++i)
		if (str[i] != str[str.length() - i - 1]) return false;

	return true;
}

int main()
{
	clock_t start, end;
	start = clock();

	int num = 0;
	int factor1, factor2;
	for (int i = 100; i <= 999; ++i)
		for (int j = 100; j <= 999; ++j)
			if (isPalindrome(i * j) && num < i * j)
			{
				num = i * j;
				factor1 = i;
				factor2 = j;
			}
	
	printf("답: %i (%i x %i)\n", num, factor1, factor2);

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
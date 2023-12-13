// Problem #000: 

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, end;
	start = clock();



	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
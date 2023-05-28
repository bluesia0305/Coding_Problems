#include <iostream>
#include <cstring>

using namespace std;

int DecomposeSum(int num)
{
	int sum = num;
	char str[7] = { 0, };
	sprintf(str, "%d", num);

	int i = 0;
	while (str[i])
		sum += (str[i++] - '0');

	return sum;
}

int main()
{
	char str[7] = { 0, };
	scanf("%s", str);

	int N = atoi(str);
	int min = N - 9 * (int)strlen(str);
	min = min ? min : 1;

	while (min < N)
	{
		if (DecomposeSum(min) == N)
		{
			printf("%d\n", min);
			break;
		}

		min++;
	}
	
	if (min == N)	printf("0\n");

	return 0;
}
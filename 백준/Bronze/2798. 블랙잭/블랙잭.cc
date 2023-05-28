#include <iostream>

using namespace std;

int main()
{
	int N, M, temp, sum = 0;
	int nums[100] = { 0, };
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	for (int i = 0; i < N - 2; i++)
	{
		if (nums[i] > M) continue;

		for (int j = i + 1; j < N - 1; j++)
		{
			if (nums[i] + nums[j] > M) continue;

			for (int k = j + 1; k < N; k++)
			{
				temp = nums[i] + nums[j] + nums[k];

				if (temp == M)
				{
					sum = temp;
					break;
				}

				if (temp < M && temp > sum)
					sum = temp;
			}
		}
	}

	printf("%d\n", sum);

	return 0;
}
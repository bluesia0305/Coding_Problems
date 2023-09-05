#include <vector>

using namespace std;

long long pulsify(vector<int> sequence, int sgn)
{
	long long maxSum = 0;
	long long sum = 0;
	int idx = 0;

	while (idx < (int)sequence.size())
	{
		int num = sgn * sequence[idx];
		if (maxSum < num)
			maxSum = num;

		if (sum + num > 0)
		{
			sum += num;
			if (maxSum < sum)
				maxSum = sum;
		}
		else
			sum = 0;

		sgn *= -1;
		idx++;
	}

	return maxSum;
}

long long solution(vector<int> sequence)
{
	long long num1 = pulsify(sequence, 1);
	long long num2 = pulsify(sequence, -1);

	return num1 > num2 ? num1 : num2;
}
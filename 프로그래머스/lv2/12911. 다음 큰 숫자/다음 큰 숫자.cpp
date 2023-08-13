int solution(int n)
{
	int answer = n, i = 1, z = 0x01, ones = 0;
	while (true)
	{
		if (n & z)
		{
			if (!(n & z << 1))
				break;

			ones++;
		}

		i++;
		z <<= 1;
	}

	answer += z << 1;
	answer -= z;

	if (ones)
		if (i - 1 > ones)
		{
			answer -= (n % z);
			int temp = 0x01;
			while (ones--)
			{
				answer += temp;
				temp <<= 1;
			}
		}

	return answer;
}
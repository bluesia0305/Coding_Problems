int solution(int n, int a, int b)
{
	int answer = 1;

	while (n > 2)
	{
		if (a + 1 == b && a % 2 ||
			b + 1 == a && b % 2)
			break;

		n /= 2;

		if (a <= n && b > n ||
			a > n && b <= n)
		{
			answer++;
			a = (a + 1) / 2;
			b = (b + 1) / 2;
		}
		else if (a > n)
		{
			a -= n;
			b -= n;
		}
	}

	return answer;
}
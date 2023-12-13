int solution(int n)
{
	if (n > 1)
	{
		if (n % 2)
			return solution(n / 2) + 1;
	
		return solution(n / 2);
	}
	
	return 1;
}
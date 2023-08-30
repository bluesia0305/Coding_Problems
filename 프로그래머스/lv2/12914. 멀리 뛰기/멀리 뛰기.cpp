using namespace std;

long long solution(int n)
{
	if (n < 3)
		return n;

	long long answer = 0;
		
	int a = 1, b = 2;
	for (int i = 2; i < n; i++)
	{
		answer = (a + b) % 1234567;
		a = b;
		b = answer;
	}
	
	return answer;
}
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int solution(vector<int> arr)
{
	int answer = 1;
	for (int n : arr)
		answer = answer * n / gcd(answer, n);

	return answer;
}
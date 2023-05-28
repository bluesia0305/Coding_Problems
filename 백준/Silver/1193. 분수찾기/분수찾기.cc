#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int N = 1;			// N <- 찾는 분수가 속한 군 번호
	while (n > N)
	{
		n -= N;
		N++;
	}					// n <- 찾는 분수가 N번째 군 내에서 가지는 번호

	// 짝수 번호 군 = numerator = n
	// 홀수 번호 군 = denominator = n
	// N번째 군의 numerator + denominator = N + 1
	if (N % 2 == 1)
		cout << (N + 1) - n << '/' << n << endl;
	else
		cout << n << '/' << (N + 1) - n << endl;
	
	return 0;
}
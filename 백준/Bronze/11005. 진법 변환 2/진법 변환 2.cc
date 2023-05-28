#include <iostream>
#include <string>

using namespace std;

char Convert(int n)
{
	return char(n <= 9 ? n + '0' : n - 10 + 'A');
}

int main()
{
	int n;
	int radix;
	int digit;
	string result;

	cin >> n >> radix;

	while (n / radix > 0)
	{
		digit = n % radix;
		n = n / radix;

		result = Convert(digit) + result;
	}
	result = Convert(n) + result;
	cout << result;

	return 0;
}
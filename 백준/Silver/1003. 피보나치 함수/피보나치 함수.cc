#include <iostream>

using namespace std;

int Fibonacci[41] = { 0, 1, };

int fibonacci(int n)
{
	if (n >= 2)
		if (!Fibonacci[n])
			Fibonacci[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return Fibonacci[n];
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		if (n)
			cout << fibonacci(n - 1) << " " << fibonacci(n) << "\n";
		else
			cout << "1 0\n";
	}
}
#include <iostream>

using namespace std;

int Factorial(int n)
{
	return n > 1 ? n * Factorial(n - 1) : 1;
}

int main()
{
	int N;
	cin >> N;
	cout << Factorial(N) << "\n";

	return 0;
}
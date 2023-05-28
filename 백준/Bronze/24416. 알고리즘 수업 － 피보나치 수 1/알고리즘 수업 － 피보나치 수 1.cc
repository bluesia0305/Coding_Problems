#include <iostream>

unsigned int f[41] = { 0, 1, 1, };
unsigned int count = 0;
using namespace std;

int fibonacci(int n)
{
	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		::count++;
	}
	return f[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	cout << fibonacci(N) << " " << ::count << "\n";

	return 0;
}
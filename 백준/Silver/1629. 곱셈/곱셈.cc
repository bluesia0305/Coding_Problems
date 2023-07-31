#include <iostream>

using namespace std;

size_t ModularPow(int a, int b, int mod)
{
	if (b == 1)
		return a;

	int e = b / 2;
	size_t n = ModularPow(a, e, mod);

	return (b % 2 ? n * n % mod * a : n * n) % mod;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << ModularPow(A % C, B, C) << "\n";
	return 0;
}
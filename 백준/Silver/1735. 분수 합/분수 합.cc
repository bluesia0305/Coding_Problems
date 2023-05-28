#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	while (b)
    {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int numer = A * D + B * C;
	int denom = B * D;

	int gcd = GCD(numer, denom);

	cout << numer / gcd << " " << denom / gcd << "\n";

	return 0;
}
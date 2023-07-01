#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(size_t n)
{
	if (n < 2)
		return false;

	for (size_t i = 2; i <= (size_t)sqrt(n) + 1; i++)
		if (!(n % i) && n != i)
			return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		size_t N;
		cin >> N;

		while (!IsPrime(N++));
		cout << N - 1 << "\n";
	}

	return 0;
}
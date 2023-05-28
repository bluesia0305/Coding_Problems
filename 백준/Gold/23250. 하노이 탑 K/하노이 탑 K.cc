#include <iostream>
#include <cmath>
using namespace std;

unsigned long long K;

void Hanoi(int n, int from, int dest, int temp)
{
	if (n > 1)
	{
		size_t k = (size_t)pow(2, n - 1) - 1;
		if (K <= k)
			Hanoi(n - 1, from, temp, dest);
		else
			K -= k;
	}
	if (!--K)
		cout << from << " " << dest << "\n";
	if (n > 1)
	{
		Hanoi(n - 1, temp, dest, from);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N >> K;
	Hanoi(N, 1, 3, 2);

	return 0;
}
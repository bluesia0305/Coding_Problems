#include <iostream>
#include <algorithm>

using namespace std;

int Divisors[50];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Divisors[i];

	sort(Divisors, Divisors + N);
	cout << Divisors[0] * Divisors[N - 1] << "\n";

	return 0;
}
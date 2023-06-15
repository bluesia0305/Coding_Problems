#include <iostream>
#include <algorithm>

using namespace std;

int Counts(int n)
{
	return n <= 1 ? 0 : min(Counts(n / 2) + n % 2, Counts(n / 3) + n % 3) + 1;
}

int main()
{
	int N;
	cin >> N;
	cout << Counts(N) << "\n";
	return 0;
}
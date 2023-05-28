#include <iostream>
#include <cmath>

using namespace std;

void Hanoi(int N, int from, int dest, int temp)
{
	if (N > 1)
		Hanoi(N - 1, from, temp, dest);

	cout << from << " " << dest << "\n";

	if (N > 1)
		Hanoi(N - 1, temp, dest, from);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	cout << (size_t)pow(2, N) - 1 << "\n";
	Hanoi(N, 1, 3, 2);

	return 0;
}
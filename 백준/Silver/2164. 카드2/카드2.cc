#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, prod = 2;
	cin >> N;

	if (N == 1)
	{
		cout << "1\n";
		return 0;
	}

	while (prod < N)
		prod *= 2;
	
	cout << 2 * N - prod << "\n";

	return 0;
}
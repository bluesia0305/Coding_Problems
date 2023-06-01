#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, X;
	cin >> N >> X;

	while (N--)
	{
		int num;
		cin >> num;

		if (num < X)
			cout << num << " ";
	}
	cout << "\n";

	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int n, memo1, memo2, result = 0;
	cin >> n;

	memo1 = 0;
	memo2 = 1;

	if (n > 1)
		for (int i = 2; i <= n; i++)
		{
			result = memo1 + memo2;
			memo1 = memo2;
			memo2 = result;
		}
	else
		result = n == 0 ? 0 : 1;

	cout << result << "\n";

	return 0;
}
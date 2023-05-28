#include <iostream>

using namespace std;

int FindWord(int n)
{
	if (n < 2)
		return 1;

	int a = 1, b = 1;
	for (int i = 2; i < n + 1; i++)
	{
		int temp = (a + b) % 15746;
		a = b;
		b = temp;
	}

	return b;
}

int main()
{
	int N;
	cin >> N;
	cout << FindWord(N) << "\n";
	return 0;
}
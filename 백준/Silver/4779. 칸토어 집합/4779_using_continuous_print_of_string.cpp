#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void Cantor(int p, int q)
{
	if (p > q)
		return;

	if (p == q)
		cout << '-';
	else
	{
		int l = (q - p + 1) / 3 - 1;
		Cantor(p, p + l);

		string space;
		for (int i = 0; i < l + 1; i++)
			space += " ";
		cout << space;

		Cantor(q - l, q);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	while (true)
	{
		cin >> N;
		if (cin.eof())
			return 0;

		int len = (int)pow(3, N);
		Cantor(0, len - 1);
		cout << "\n";
	}
}
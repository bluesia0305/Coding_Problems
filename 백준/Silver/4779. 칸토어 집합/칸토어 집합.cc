#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void Cantor(char* set, int p, int q)
{
	if (p > q)
		return;

	if (p == q)
		set[p] = '-';
	else
	{
		int l = (q - p + 1) / 3 - 1;
		Cantor(set, p, p + l);
		Cantor(set, q - l, q);
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
		char* CantorSet = new char[len + 1];
		memset(CantorSet, ' ', sizeof(char) * len);
		CantorSet[len] = '\0';

		Cantor(CantorSet, 0, len - 1);

		cout << CantorSet << "\n";
		delete[] CantorSet;
	}
}
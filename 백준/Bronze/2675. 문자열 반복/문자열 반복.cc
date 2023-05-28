#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string Word;
	int N, Repeat;
	cin >> N;

	while (N--)
	{
		cin >> Repeat >> Word;
		for (char c : Word)
			for (int j = 0; j < Repeat; j++)
				cout << c;

		cout << "\n";
	}

	return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int A, P;
	cin >> A >> P;

	unordered_map<int, int> Sequences;

	int i = 0;
	while (true)
	{
		int size = Sequences.size();
		Sequences.try_emplace(A, i++);

		if (Sequences.size() == size)
		{
			cout << Sequences.at(A) << "\n";
			return 0;
		}

		string a = to_string(A);
		A = 0;
		for (char c : a)
			A += (int)pow(c - '0', P);
	}
}
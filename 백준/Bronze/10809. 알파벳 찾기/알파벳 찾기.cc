#include <iostream>
#include <string>

using namespace std;

int Alphabets[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int& value : Alphabets)
		value = -1;

	string Word;
	cin >> Word;

	for (int i = 0; i < Word.length(); i++)
		if (Alphabets[(Word[i] - 'a')] == -1)
			Alphabets[(Word[i] - 'a')] = i;

	for (int c : Alphabets)
		cout << c << " ";

	return 0;
}
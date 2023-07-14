#include <iostream>
#include <string>

using namespace std;
int Freqs[26][200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string Str;
	int Q;
	cin >> Str >> Q;

	int DP[26] = { 0, };
	for (int i = 0; i < Str.size(); i++)
	{
		DP[Str[i] - 'a']++;
		for (int j = 0; j < 26; j++)
			Freqs[j][i + 1] = DP[j];
	}
	
	while (Q--)
	{
		char word;
		int l, r;
		cin >> word >> l >> r;
		cout << Freqs[word - 'a'][r + 1] - Freqs[word - 'a'][l] << "\n";
	}

	return 0;
}
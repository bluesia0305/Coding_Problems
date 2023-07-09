#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> Words;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M = 0;
	cin >> N >> M;

	while(N--)
	{
		string str;
		cin >> str;

		if (str.size() < M)
			continue;

		Words[str]++;
	}

	vector<string> Sorted;

	for (auto iter = Words.begin(); iter != Words.end(); iter++)
		Sorted.push_back(iter->first);

	sort(Sorted.begin(), Sorted.end(),
		 [](const string& str1, const string& str2)
		 {
			 if (Words[str1] == Words[str2])
			 {
				 if (str1.size() == str2.size())
					 return str1 < str2;

				 return str1.size() > str2.size();
			 }
			 return Words[str1] > Words[str2];
		 });

	for (string str : Sorted)
		cout << str << "\n";

	return 0;
}
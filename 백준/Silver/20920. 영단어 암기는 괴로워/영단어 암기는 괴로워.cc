#include <iostream>
#include <string>
#include <cstring>
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

	while (N--)
	{
		char str[11];
		cin >> str;

		if (strlen(str) < M)
			continue;

		Words[str]++;
	}

	vector<pair<string, int>> Sorted(Words.begin(), Words.end());
	sort(Sorted.begin(), Sorted.end(),
		 [&](const pair<string, int>& pair1, const pair<string, int>& pair2)
		 {
			 if (pair1.second == pair2.second)
			 {
				 if (pair1.first.size() == pair2.first.size())
					 return pair1.first < pair2.first;

				 return pair1.first.size() > pair2.first.size();
			 }
			 return pair1.second > pair2.second;
		 });

	for (const pair<string, int>& pair : Sorted)
		cout << pair.first << "\n";

	return 0;
}
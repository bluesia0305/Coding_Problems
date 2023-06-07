#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	unordered_set<string> Set;

	while (N--)
	{
		string name, op;
		cin >> name >> op;
		if (op == "enter")
			Set.emplace(name);
		else if (op == "leave")
			Set.erase(Set.find(name));
	}

	vector<string> Sorted(Set.begin(), Set.end());
	sort(Sorted.begin(), Sorted.end(), [](string s1, string s2) { return s1 > s2; });

	for (string str : Sorted)
		cout << str << "\n";

	return 0;
}
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Count = 0;
	cin >> N;

	unordered_set<string> gomgom;
	string str;
	while (N--)
	{
		cin >> str;

		if (str == "ENTER")
		{
			Count += gomgom.size();
			unordered_set<string>().swap(gomgom);
			continue;
		}

		gomgom.insert(str);
	}
	Count += gomgom.size();
	cout << Count << "\n";
	return 0;
}
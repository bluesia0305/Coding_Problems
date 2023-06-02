#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Count = 0;
	cin >> N;

	set<string> gomgom;
	string str;
	while (N--)
	{
		cin >> str;

		if (str == "ENTER")
		{
			Count += gomgom.size();
			gomgom.clear();
			continue;
		}

		gomgom.emplace(str);
	}
	Count += gomgom.size();
	cout << Count << "\n";
	return 0;
}
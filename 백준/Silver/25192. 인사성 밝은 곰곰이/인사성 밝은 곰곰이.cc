#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int N, Count = 0;
	cin >> N;

	map<string, int> gomgom;
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

		gomgom.try_emplace(str, 1);
	}
	Count += gomgom.size();
	cout << Count << "\n";
	return 0;
}
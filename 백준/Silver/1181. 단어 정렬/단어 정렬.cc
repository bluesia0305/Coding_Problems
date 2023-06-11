#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Strings[20000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Strings[i];

	sort(&Strings[0], &Strings[N - 1] + 1,
		 [](const string& a, const string& b)
		 {
			 if (a.length() == b.length())
				 return a < b;
			 return a.length() < b.length();
		 });

	string temp;
	for (int i = 0; i < N; i++)
		if (Strings[i] != temp)
			cout << (temp = Strings[i]) << "\n";

	return 0;
}
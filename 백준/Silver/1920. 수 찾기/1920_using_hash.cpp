#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> Numbers;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		Numbers.emplace(num);
	}

	cin >> N;
	while(N--)
	{
		int num;
		cin >> num;
		auto iter = Numbers.find(num);
		cout << (iter != Numbers.end() ? "1" : "0") << "\n";
	}

	return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Worker
{
	char Name[6];
	bool Entered;
};

size_t HashFunction(char str[6])
{
	size_t hash = 0, power = 1;
	for (int i = 4; i >= 0; i--)
	{
		if (str[i])
			hash += power * (str[i] - 'A' + 1);

		power *= 59;
	}
	return hash;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	map<size_t, Worker,std::greater<>> Workers;

	while (N--)
	{
		Worker worker;
		char op[6] = { 0, };

		cin >> worker.Name >> op;
		worker.Entered = op[0] == 'e';
		Workers[HashFunction(worker.Name)] = worker;
	}

	//vector<pair<size_t, Worker>> Sorted(Workers.begin(), Workers.end());
	//sort(Sorted.begin(), Sorted.end(), [](pair<size_t, Worker> a, pair<size_t, Worker> b) { return a.first > b.first; });
	//for (auto elem : Sorted)
	//	if (elem.second.Entered)
	//		cout << elem.second.Name << "\n";
	//
	for (auto elem : Workers)
		if (elem.second.Entered)
			cout << elem.second.Name << "\n";

	return 0;
}
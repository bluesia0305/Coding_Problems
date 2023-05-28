#include <iostream>
#include <string>
#include <vector>
#include <map>

#define PRIME 29;
#define MODULO 4565710823;	// large prime number

using namespace std;

// polynomial rolling hash
size_t HashFunction(string str)
{
	size_t hash = 0;
	size_t power = 1;
	for (char c : str)
	{
		hash += power * c;
		power *= PRIME;
	}

	return hash % MODULO;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<size_t, vector<string>> HashTable;

	int N, M, Count = 0;
	cin >> N >> M;

	while (N--)
	{
		string str;
		cin >> str;

		vector<string> temp;
		size_t hash = HashFunction(str);
		HashTable.try_emplace(hash, temp);
		HashTable.at(hash).push_back(str);
	}

	while (M--)
	{
		string query;
		cin >> query;

		size_t hash = HashFunction(query);
		auto iter = HashTable.find(hash);
		if (iter != HashTable.end())
		{
			for (const string& str : (*iter).second)
			{
				if (query == str)
				{
					Count++;
					break;
				}
			}
		}
	}

	cout << Count << "\n";

	return 0;
}
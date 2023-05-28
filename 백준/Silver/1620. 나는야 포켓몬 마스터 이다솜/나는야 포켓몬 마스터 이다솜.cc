#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#define PRIME 53;
#define MODULO 4565710823;	// large prime number

using namespace std;

struct Pokemon
{
	char Name[21];
};

// polynomial rolling hash
size_t HashFunction(char str[21])
{
	size_t hash = 0;
	size_t power = 1;
	for (int i = 0; i < 21; i++)
	{
		if (!str[i]) break;

		hash += power * (str[i] - 'a' + 1);
		power *= PRIME;
	}

	return hash % MODULO;
}

int main()
{
	int N, M, Num = 1;
	scanf("%d %d", &N, &M);

	vector<Pokemon> Pokemons(N);
	map<size_t, vector<int>> HashTable;

	while (N--)
	{
		Pokemon pokemon;
		scanf("%s", pokemon.Name);
		Pokemons[Num - 1] = pokemon;

		size_t hash = HashFunction(pokemon.Name);
		HashTable.try_emplace(hash, vector<int>());
		HashTable.at(hash).push_back(Num++);
	}

	while (M--)
	{
		char query[21] = { 0, };
		scanf("%s", query);

		if (query[0] <= '9')
			printf("%s\n", Pokemons[atoi(query) - 1].Name);
		else
		{
			size_t hash = HashFunction(query);
			for (int num : HashTable[hash])
			{
				if (!strcmp(query, Pokemons[num - 1].Name))
				{
					printf("%d\n", num);
					break;
				}
			}
		}
	}

	return 0;
}
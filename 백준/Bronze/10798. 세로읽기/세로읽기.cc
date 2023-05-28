#include <iostream>
#include <string>

#define MAX_LINES 5
#define MAX_WORDS 15

using namespace std;

int main()
{
	string word[MAX_LINES];
	
	for (int i = 0; i < MAX_LINES; i++)
		getline(cin, word[i]);

	for (int i = 0; i < MAX_WORDS; i++)
	{
		for (int j = 0; j < MAX_LINES; j++)
		{
			if (i < word[j].length())
				cout << word[j][i];
		}
	}

	return 0;
}
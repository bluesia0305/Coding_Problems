#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char str[101] = { 0, };
	cin >> str;

	bool isPalindrome = true;
	for (int i = 0; i < strlen(str); i++)
	{
		if (i >= strlen(str) - 1 - i)
			break;

		if (str[i] != str[strlen(str) - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	cout << (int)isPalindrome << "\n";
	return 0;
}
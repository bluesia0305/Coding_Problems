#include <iostream>
#include <string.h>

using namespace std;

int cnt;

int recursion(const char* s, int l, int r)
{
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		char str[1001] = { 0, };
		scanf("%s", str);

		cnt = 0;
		int result = isPalindrome(str);
		printf("%d %d\n", result, cnt);
	}
}
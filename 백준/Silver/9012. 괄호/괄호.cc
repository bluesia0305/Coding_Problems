#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	char str[50] = { 0, };

	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);

		int count = 0;
		for (char c : str)
		{
			if (c == '(') count++;
			if (c == ')') count--;
			//printf("%d ", count);			// PRINT TEST
			if (!c || count < 0) break;
		}

		if (count)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
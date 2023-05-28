#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int end = 1, i = 1;
	while (n > end)
		end += (6 * i++);
	
	cout << i;

	return 0;
}
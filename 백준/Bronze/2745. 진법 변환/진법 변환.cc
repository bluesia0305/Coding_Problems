#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string n;
	int radix;
	int result = 0;

	cin >> n >> radix;

	for (size_t i = 0; i < n.size(); i++)
		result += (n[i] <= '9' ? n[i] - '0' : n[i] - 'A' + 10) * static_cast<int>(pow(radix, n.size() - 1 - i));

	cout << result;

	return 0;
}
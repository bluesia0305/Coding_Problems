#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, Sum = 0;
	cin >> N;

	string num;
	cin >> num;

	for (char c : num)
		Sum += c - '0';

	cout << Sum << "\n";
}
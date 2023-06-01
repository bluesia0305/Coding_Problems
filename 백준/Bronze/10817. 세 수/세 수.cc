#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	array<int, 3> Nums;
	cin >> Nums[0] >> Nums[1] >> Nums[2];

	sort(Nums.begin(), Nums.end(), [](int a, int b) { return a > b; });
	cout << Nums[1] << "\n";

	return 0;
}
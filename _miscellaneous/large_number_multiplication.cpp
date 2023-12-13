#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MultiplyN(string& largeNum, int n)
{
	bool negative = false;
	if (largeNum[0] == '-')
	{
		negative = true;
		largeNum.erase(largeNum.begin());
	}

	vector<int> result;
	for (int i = 0; i < (int)log10(abs(n)) + 2; i++)
		result.push_back(0);

	for (char c : largeNum)
		result.push_back((c - '0') * abs(n));

	for (size_t i = result.size() - 1; i > 1; --i)
	{
		if (result[i])
		{
			result[i - 1] += result[i] / 10;
			result[i] = result[i] % 10;
		}
	}

	while (!result[0])
		result.erase(result.begin());

	if (negative)
		largeNum = n > 0 ? "-" : "";
	else
		largeNum = n > 0 ? "" : "-";

	for (int c : result)
		largeNum += to_string(c);
}

int main()
{
	int base = -2;
	int exponent = 6;

	string pow2_string = "1";
	for (int i = 0; i < exponent; i++)
		MultiplyN(pow2_string, base);
	cout << "string 클래스를 이용한 계산 결과(base, exponent가 int 범위 내이면 항상 정확):" << "\n";
	cout << pow2_string << "\n";
}
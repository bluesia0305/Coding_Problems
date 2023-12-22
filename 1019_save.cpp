#include <iostream>
#include <string>

using namespace std;

int Nums[10];

void Find2(int n)
{
	int nums[10] = { 0, };
	for (int i = 1; i <= n; i++)
	{
		string s = to_string(i);
		for (char c : s)
			nums[c - '0']++;
	}

	cout << n << "\t: ";
	for (int n : nums)
		cout << n << " ";
	cout << "\n";
}

void Find(int n)
{
	int aux = 0;
	int msd = 1;
	
	string str = to_string(n);
	if (str.back() - '0' > 0)
		Nums[str.back() - '0']++;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		int digit = str[i] - '0';
		for (int i = 1; i < 10; i++)
			Nums[i] += aux * digit;
			
		for (int i = 1; i < digit; i++)
			Nums[i] += msd;

		if (i < str.size() - 1)
			Nums[digit] += stoi(str.substr(i + 1)) + 1;

		aux = aux * 10 + msd;
		msd *= 10;
	}

	for (int i = str.size() - 2; i >= 0; i--)
	{
		int digit = str[i] - '0';
	}
}

int main()
{
	for (int i = 1; i <= 500; i++)
		Find2(i);

	//int n;
	//cin >> n;
	//
	//Find(n);
	//
	//for (int num : Nums)
	//	cout << num << " ";
	//cout << "\n";
	return 0;
}
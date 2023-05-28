#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	vector<int> factors = { 1 };

	while (true)
	{
		cin >> n;

		if (n == -1)
			break;

		int sum_factors = 1;
		for (int i = 2; ; i++)
		{
			if (i * i >= n)
				break;

			if (!(n % i))
			{
				// i is a factor
				factors.push_back(i);
				sum_factors += i;

				// factor pair
				factors.push_back(n / i);
				sum_factors += (n / i);
			}
		}
		sort(factors.begin(), factors.end());

		cout << n;
		if (sum_factors == n && n > 2)
		{
			// perfect number
			cout << " = ";
			for (int factor : factors)
			{
				cout << factor;
				if (factor != factors.back())
					cout << " + ";
			}
		}
		else
		{
			// not perfect number	
			cout << " is NOT perfect.";
		}

		cout << endl;
		factors.clear();
		factors.push_back(1);
	}

	return 0;
}
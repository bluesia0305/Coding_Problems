#include <iostream>
#include <string>

using namespace std;

int main()
{
	string Expr;
	cin >> Expr;

	int sum = 0;
	for (int i = (int)Expr.size() - 1; i > 0; i--)
	{
		if (Expr[i] == '-')
		{
			sum -= stoi(Expr.substr(i + 1));
			Expr = Expr.substr(0, i);
		}
		else if (Expr[i] == '+')
		{
			int lhs = i;
			while (lhs--)
			{
				if (lhs > 0)
				{
					if (!(Expr[lhs] >= '0' && Expr[lhs] <= '9'))
					{
						lhs++;
						break;
					}
				}
				else
					break;
			}
			Expr = Expr.substr(0, lhs) + to_string(stoi(Expr.substr(lhs, i - lhs)) + stoi(Expr.substr(i + 1)));
		}
	}
	sum += stoi(Expr);

	cout << sum << "\n";
	return 0;
}
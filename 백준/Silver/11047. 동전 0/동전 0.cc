#include <iostream>
#include <stack>

using namespace std;

stack<int> Coins;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Money, NumCoins = 0;
	cin >> N >> Money;

	while (N--)
	{
		int Coin;
		cin >> Coin;

		if (Coin > Money)
			break;

		Coins.push(Coin);
	}

	while (Money != 0)
	{
		int Coin = Coins.top();
		Coins.pop();

		NumCoins += Money / Coin;
		Money %= Coin;
	}

	cout << NumCoins << "\n";
	return 0;
}
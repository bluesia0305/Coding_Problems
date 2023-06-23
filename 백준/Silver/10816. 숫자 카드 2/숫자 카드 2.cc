#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N;
	unordered_map<int, int> Cards;

	while (N--)
	{
		int card;
		cin >> card;
		Cards[card]++;
	}

	cin >> M;
	while (M--)
	{
		int card;
		cin >> card;
		cout << Cards[card] << " ";
	}
	cout << "\n";

	return 0;
}
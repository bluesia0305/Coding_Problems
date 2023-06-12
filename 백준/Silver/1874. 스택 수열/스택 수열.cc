#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> Op;
stack<int> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, n = 1;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (S.empty() || S.top() < num)
		{
			Op.push_back('+');
			S.push(n++);
		}

		if (S.top() == num)
		{
			Op.push_back('-');
			S.pop();
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}

	for (char c : Op)
		cout << c << "\n";

	return 0;
}
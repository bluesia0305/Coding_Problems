#include <iostream>
#include <queue>

using namespace std;

deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	int Count = 0;
	while (M--)
	{
		int num;
		cin >> num;

		int cnt = 0;
		while (num != dq.front())
		{
			int temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
			cnt++;
		}
		dq.pop_front();

		if (cnt > dq.size() + 1 - cnt)
			cnt = dq.size() + 1 - cnt;
		
		Count += cnt;
	}

	cout << Count << "\n";
	return 0;
}
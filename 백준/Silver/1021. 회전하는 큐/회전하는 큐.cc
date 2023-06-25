#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		q.push(i);

	int Count = 0;
	while (M--)
	{
		int num;
		cin >> num;

		int cnt = 0;
		while (num != q.front())
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
			cnt++;
		}

		if (cnt > q.size() - cnt)
			cnt = q.size() - cnt;

		q.pop();
		Count += cnt;
	}

	cout << Count << "\n";
	return 0;
}
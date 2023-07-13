#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, Sum = 0;
	cin >> N;

	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < N; i++)
	{
		int time;
		cin >> time;
		pq.emplace(time);
	}

	while (!pq.empty())
	{
		int time = pq.top();
		pq.pop();

		Sum += time * N--;
	}

	cout << Sum << "\n";
	return 0;
}
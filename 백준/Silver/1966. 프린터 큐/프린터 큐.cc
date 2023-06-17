#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Data
{
	int Index;
	int Priority;
};

int main()
{
	int T, N, M;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		queue<Data> Queue;
		vector<int> Priorities(N);
		for (int i = 0; i < N; i++)
		{
			int priority;
			cin >> priority;
			Priorities.push_back(priority);
			Queue.push(Data{ i, priority });
		}

		sort(Priorities.begin(), Priorities.end());

		int order = 0;
		while (!Queue.empty())
		{
			Data data = Queue.front();
			Queue.pop();

			int priority = Priorities.back();
			if (data.Priority < priority)
				Queue.push(data);
			else
			{
				order++;
				Priorities.pop_back();

				if (data.Index == M)
				{
					cout << order << "\n";;
					break;
				}
			}
		}
	}
	
	return 0;
}
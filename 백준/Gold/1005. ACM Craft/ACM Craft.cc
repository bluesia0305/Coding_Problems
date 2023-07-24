#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Build
{
	vector<int> NextIndexes;
	int EntDegree = 0;
	int Time = 0;
	int TimeDP = 0;
};

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		Build Buildings[1000];
		int N, K, W;
		cin >> N >> K;
		for (int i = 0; i < N; i++)
			cin >> Buildings[i].Time;

		while (K--)
		{
			int from, dest;
			cin >> from >> dest;
			++Buildings[dest - 1].EntDegree;
			Buildings[from - 1].NextIndexes.push_back(dest - 1);
		}

		cin >> W;
		queue<int> builds;
		for (int i = 0; i < N; i++)
			if (!Buildings[i].EntDegree)
				builds.push(i);

		while (!builds.empty())
		{
			int currIndex = builds.front();
			builds.pop();

			Build& current = Buildings[currIndex];
			if (currIndex == W - 1)
			{
				cout << Buildings[currIndex].TimeDP + Buildings[currIndex].Time << "\n";
				break;
			}

			int time = current.TimeDP + current.Time;
			for (int idx : current.NextIndexes)
			{
				--Buildings[idx].EntDegree;
				if (Buildings[idx].TimeDP < time)
					Buildings[idx].TimeDP = time;

				if (!Buildings[idx].EntDegree)
					builds.push(idx);
			}
		}
	}

	return 0;
}
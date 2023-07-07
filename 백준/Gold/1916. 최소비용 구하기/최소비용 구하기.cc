#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int From;
	int Dest;
	int Cost;
};

struct City
{
	int CostSum = 2147483647;
	bool Visited = false;
	vector<Edge> Edges;
};

City Cities[1000];

struct cmp
{
	bool operator()(const int& idx1, const int& idx2) const
	{
		return Cities[idx1].CostSum > Cities[idx2].CostSum;
	}
};

void Dijkstra(int start, int end)
{
	if (start == end)
	{
		cout << "0\n";
		return;
	}

	Cities[start - 1].CostSum = 0;

	priority_queue<int, vector<int>, cmp> pq;
	pq.push(start - 1);
	while (!pq.empty())
	{
		int index = pq.top();
		pq.pop();

		City& current = Cities[index];
		current.Visited = true;

		if (index == end - 1)
		{
			cout << current.CostSum << "\n";
			return;
		}

		for (Edge e : current.Edges)
		{
			if (!Cities[e.Dest].Visited &&
				Cities[e.Dest].CostSum > current.CostSum + e.Cost)
			{
				Cities[e.Dest].CostSum = current.CostSum + e.Cost;
				pq.push(e.Dest);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, dest, cost;
		cin >> from >> dest >> cost;
		Cities[from - 1].Edges.push_back(Edge{ from - 1, dest - 1, cost });
	}

	for (City& city : Cities)
		sort(city.Edges.begin(), city.Edges.end(), [](const Edge& A, const Edge& B) { return A.Cost < B.Cost; });

	int Start, End;
	cin >> Start >> End;
	Dijkstra(Start, End);
	return 0;
}
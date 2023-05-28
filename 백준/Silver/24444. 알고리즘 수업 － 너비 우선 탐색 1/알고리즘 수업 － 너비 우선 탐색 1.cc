#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Graph
{
	struct Vertex
	{
		vector<int> NextIndex;
		int VisitOrder = 0;
	};

	Graph(int N)
	{
		V = vector<Vertex>(N);
	}

	void AddEdge(int From, int Dest)
	{
		V[From - 1].NextIndex.push_back(Dest);
	}

	void SortEdge()
	{
		for (Vertex& v : V)
			sort(v.NextIndex.begin(), v.NextIndex.end());
	}

	void BFS(int start)
	{
		Queue.push(start);
		while (!Queue.empty())
		{
			int index = Queue.front();
			Vertex& vertex = V[index - 1];
			Queue.pop();

			if (!vertex.VisitOrder)
			{
				vertex.VisitOrder = Order++;
				for (int nextIndex : vertex.NextIndex)
					Queue.push(nextIndex);
			}
		}
	}

	vector<Vertex> V;
	queue<int> Queue;
	int Order = 1;
};

int main()
{
	int N, M, R;
	scanf("%d %d %d", &N, &M, &R);

	Graph graph = Graph(N);

	int from, dest;
	while (M--)
	{
		scanf("%d %d", &from, &dest);
		graph.AddEdge(from, dest);
		graph.AddEdge(dest, from);
	}

	graph.SortEdge();
	graph.BFS(R);

	for (Graph::Vertex v : graph.V)
		printf("%d\n", v.VisitOrder);

	return 0;
}
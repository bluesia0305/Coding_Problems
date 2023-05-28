#include <iostream>
#include <vector>
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
		{
			sort(v.NextIndex.begin(), v.NextIndex.end());
		}
	}

	void DFS(int index)
	{
		Vertex& currV = V[index - 1];
		currV.VisitOrder = Order++;
		for (int index : currV.NextIndex)
		{
			if (!V[index - 1].VisitOrder)
				DFS(index);
		}
	}

	vector<Vertex> V;
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
	graph.DFS(R);

	for (Graph::Vertex v : graph.V)
		printf("%d\n", v.VisitOrder);

	return 0;
}
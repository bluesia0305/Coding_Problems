#include <iostream>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

struct Graph
{
	struct Vertex
	{
		vector<int> NextIndex;
		bool Visited = false;
	};

	Graph(int N)
	{
		V = vector<Vertex>(N);
	}

	void AddEdge(int From, int Dest)
	{
		V[From - 1].NextIndex.push_back(Dest);
	}

	void DFS(int index)
	{
		Vertex& currV = V[index - 1];
		currV.Visited = true;
		for (int index : currV.NextIndex)
		{
			if (!V[index - 1].Visited)
				DFS(index);
		}
	}

	int Affected()
	{
		int Count = 0;
		for (Vertex v : V)
			if (v.Visited)
				Count++;

		return Count;
	}

	vector<Vertex> V;
};


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	Graph graph = Graph(N);

	int from, dest;
	while (M--)
	{
		scanf("%d %d", &from, &dest);
		graph.AddEdge(from, dest);
		graph.AddEdge(dest, from);
	}

	graph.DFS(1);
	printf("%d\n", graph.Affected() - 1);

	return 0;
}
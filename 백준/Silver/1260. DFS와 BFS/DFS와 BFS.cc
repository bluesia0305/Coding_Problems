#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Graph
{
	struct Vertex
	{
		vector<int> NextIndex;
		bool VisitedByDFS = false;
		bool VisitedByBFS = false;
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

	void DFS(int startIndex)
	{
		printf("%d", startIndex);

		Stack.push(startIndex);
		while (!Stack.empty())
		{
			int index = Stack.top();
			Stack.pop();

			Vertex& vertex = V[index - 1];
			if (!vertex.VisitedByDFS)
			{
				vertex.VisitedByDFS = true;

				if (index != startIndex)
					printf(" %d", index);

				if (!vertex.NextIndex.empty())
				{
					for (size_t i = vertex.NextIndex.size(); i > 0; i--)
						Stack.push(vertex.NextIndex[i - 1]);
				}
			}
		}
		printf("\n");
	}

	void BFS(int startIndex)
	{
		printf("%d", startIndex);

		Queue.push(startIndex);
		while (!Queue.empty())
		{
			int index = Queue.front();
			Queue.pop();

			Vertex& vertex = V[index - 1];
			if (!vertex.VisitedByBFS)
			{
				vertex.VisitedByBFS = true;

				if (index != startIndex)
					printf(" %d", index);

				for (int nextIndex : vertex.NextIndex)
					Queue.push(nextIndex);
			}
		}
		printf("\n");
	}

	vector<Vertex> V;
	queue<int> Queue;
	stack<int> Stack;
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
	graph.BFS(R);

	return 0;
}
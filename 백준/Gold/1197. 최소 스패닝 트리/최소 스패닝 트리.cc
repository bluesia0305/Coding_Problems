#include <iostream>
#include <queue>

using namespace std;

struct Edge	{ int From, Dest, Weight; };
struct cmp	{ bool operator()(Edge a, Edge b) const { return a.Weight > b.Weight; } };

priority_queue<Edge, vector<Edge>, cmp> Edges;
int Verticies[10000];

int Find(int a)
{
	if (a == Verticies[a])
		return a;

	return Verticies[a] = Find(Verticies[a]);
}

void Union(int a, int b)
{
	if (a == b)
		return;

	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)
		return;

	Verticies[pb] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E, TotalWeight = 0;
	cin >> V >> E;

	for (int i = 0; i < V; i++)
		Verticies[i] = i;

	while (E--)
	{
		int from, dest, weight;
		cin >> from >> dest >> weight;
		Edges.emplace(Edge{ from - 1, dest - 1, weight });
	}

	while (!Edges.empty())
	{
		Edge edge = Edges.top();
		Edges.pop();

		if (Find(edge.From) == Find(edge.Dest))
			continue;

		Union(edge.From, edge.Dest);
		TotalWeight += edge.Weight;
	}

	cout << TotalWeight << "\n";
	return 0;
}
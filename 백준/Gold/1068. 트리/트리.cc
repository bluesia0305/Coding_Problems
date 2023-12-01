#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int Parent;
	int NumChild;
	bool Visited;
	bool Deleted;
};

Node Tree[50];
queue<int> q;
int LeafCount;

void Find(int idx)
{
	int current = idx;
	bool isdel = false;

	while (true)
	{
		q.push(current);
		Tree[current].Visited = true;

		if (Tree[current].Deleted)
		{
			isdel = true;
			break;
		}

		if (Tree[current].Parent == -1)
			break;

		current = Tree[current].Parent;
	}

	if (isdel)
	{
		while (!q.empty())
		{
			int i = q.front();
			q.pop();

			Tree[i].Deleted = true;
		}
	}
	else
		q = queue<int>();
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Tree[i].Parent;
		if (Tree[i].Parent >= 0)
			Tree[Tree[i].Parent].NumChild++;
	}

	int deleted;
	cin >> deleted;
	Tree[deleted].Deleted = true;

	for (int i = 0; i < N; i++)
		if (Tree[i].Visited == false)
			Find(i);

	for (int i = 0; i < N; i++)
		if (Tree[i].Deleted)
			if (Tree[i].Parent != -1)
				Tree[Tree[i].Parent].NumChild--;

	for (int i = 0; i < N; i++)
		if (Tree[i].NumChild == 0 && Tree[i].Deleted == false)
			LeafCount++;
	
	cout << LeafCount << "\n";
	return 0;
}
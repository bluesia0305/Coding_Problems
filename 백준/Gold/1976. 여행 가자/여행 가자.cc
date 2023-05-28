#include <iostream>

using namespace std;

int* Sets = new int[201];

int Find(int a)
{
	if (a == Sets[a])
		return a;

	return Sets[a] = Find(Sets[a]);
}

void Union(int a, int b)
{
	if (a == b)
		return;

	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)
		return;

	Sets[pb] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, Start, City;
	bool Connected;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		Sets[i] = i;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Connected;
			if (Connected)
				Union(i, j);
		}
	}

	cin >> Start;
	Start = Find(Start);
	M--;
	while (M--)
	{
		cin >> City;
		
		if (Start != Find(City))
		{
			cout << "NO" << "\n";
			return 0;
		}
	}

	cout << "YES" << "\n";
	delete[] Sets;
	return 0;
}
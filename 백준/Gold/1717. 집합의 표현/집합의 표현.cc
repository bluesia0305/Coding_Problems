#include <iostream>

using namespace std;

int* Sets = new int[1000001];

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

	int N, M, Op, A, B;
	cin >> N >> M;

	for (int i = 0; i < N + 1; i++)
		Sets[i] = i;

	while (M--)
	{
		cin >> Op >> A >> B;

		if (Op)
			cout << (Find(A) == Find(B) ? "YES" : "NO") << "\n";
		else
			Union(A, B);
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
public:
	struct Set
	{
		int Data;
		Set* Parent;
	};

	static Set* MakeSet(int data)
	{
		Set* set = new Set();
		set->Parent = set;
		set->Data = data;
		return set;
	}

	static void Union(Set* a, Set* b)
	{
		if (a == b)
			return;

		Set* pa = Find(a);
		Set* pb = Find(b);
		if (pa == pb)
			return;

		pb->Parent = a;
	}

	static Set* Find(Set* a)
	{
		if (a == a->Parent)
			return a;

		return a->Parent = Find(a->Parent);
	}

	static void Decision(Set* a, Set* b) { cout << (Find(a) == Find(b) ? "YES" : "NO") << "\n"; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, Op, A, B;
	cin >> N >> M;

	vector<DisjointSet::Set*> Sets(N + 1);

	while (M--)
	{
		cin >> Op >> A >> B;

		if (Sets[A] == nullptr)
			Sets[A] = DisjointSet::MakeSet(A);

		if (Sets[B] == nullptr)
			Sets[B] = DisjointSet::MakeSet(B);

		if (Op)
			DisjointSet::Decision(Sets[A], Sets[B]);
		else
			DisjointSet::Union(Sets[A], Sets[B]);
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void expansion(vector<int> seq, int start, int n, int m)
{
	seq.push_back(start);
	if (seq.size() == m)
	{
		for (int i : seq)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = start + 1; i <= n; i++)
		expansion(seq, i, n, m);
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> seq;
	for (int i = 1; i <= N - M + 1; i++)
		expansion(seq, i, N, M);
	return 0;
}
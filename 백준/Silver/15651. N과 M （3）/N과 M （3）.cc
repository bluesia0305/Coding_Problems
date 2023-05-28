#include <iostream>

using namespace std;

void PrintSequence(int Sequence[7], int M)
{
	for (int i = 0; i < M - 1; i++)
		cout << Sequence[i] << " ";

	cout << Sequence[M - 1] << "\n";
}

void NextTerm(int N, int M, int Sequence[7], int num, int term)
{
	Sequence[term++ - 1] = num;

	if (term > M)
	{
		PrintSequence(Sequence, M);
		return;
	}

	for (int i = 1; i <= N; i++)
		NextTerm(N, M, Sequence, i, term);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int Sequence[7] = { 0, };
	for (int i = 1; i <= N; i++)
		NextTerm(N, M, Sequence, i, 1);

	return 0;
}
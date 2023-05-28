#include <iostream>
#include <vector>

using namespace std;

void PrintSequence(int* const sequence, int M)
{
	printf("%d", sequence[0]);

	for (int i = 1; i < M; i++)
		printf(" %d", sequence[i]);

	printf("\n");
}

void NextTerm(bool* const visited, int* const sequence, int N, int M, int num, int term)
{
	visited[num - 1] = true;
	sequence[term++ - 1] = num;

	for (int i = 1; i <= N; i++)
		if (i != num && !visited[i - 1] && term <= M)
			NextTerm(visited, sequence, N, M, i, term);

	if (term > M)
		PrintSequence(sequence, M);

	visited[sequence[--term - 1] - 1] = false;
}

void FindSequences(bool* const visited, int* const sequence, int N, int M)
{
	for (int i = 1; i <= N; i++)
		NextTerm(visited, sequence, N, M, i, 1);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	bool Visited[8] = { false, };
	int Sequence[8] = { 0, };

	FindSequences(Visited, Sequence, N, M);

	return 0;
}
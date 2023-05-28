#include <iostream>

using namespace std;

class SequenceGenerator
{
public:
	SequenceGenerator(int n, int m) : N(n), M(m) {}

	void PrintSequence()
	{
		for (int i = 0; i < M - 1; i++)
			cout << Sequence[i] << " ";

		cout << Sequence[M - 1] << "\n";
	}

	void NextTerm(int num, int term)
	{
		Sequence[term++ - 1] = num;

		if (term > M)
		{
			PrintSequence();
			return;
		}

		for (int i = 1; i <= N; i++)
			if(i >= num) NextTerm(i, term);
	}

	void FindSequences()
	{
		for (int i = 1; i <= N; i++)
			NextTerm(i, 1);
	}

private:
	const int N, M;
	int Sequence[7] = { 0, };
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	SequenceGenerator seq(N, M);
	seq.FindSequences();

	return 0;
}
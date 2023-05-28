#include <iostream>

using namespace std;

int K;
int* tmp;

void merge(int* A, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 0;
	while (i <= q and j <= r)
	{
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}

	while (i <= q)
		tmp[t++] = A[i++];

	while (j <= r)
		tmp[t++] = A[j++];

	i = p;
	t = 0;
	while (i <= r)
	{
		A[i++] = tmp[t++];
		if (!--K)
		{
			cout << A[i - 1];
			return;
		}
	}
}

void merge_sort(int* A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		if (!K) return;
		merge_sort(A, q + 1, r);
		if (!K) return;
		merge(A, p, q, r);
		if (!K) return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N >> K;

	int* A = new int[N];
	tmp = new int[N];

	for (int i = 0; i < N; i++)
		cin >> A[i];

	merge_sort(A, 0, N - 1);
	if (K > 0) cout << "-1\n";

	delete[] A;
	delete[] tmp;
	return 0;
}
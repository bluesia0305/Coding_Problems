#include <iostream>
#include <vector>

using namespace std;

int N;
int Min = 400;

int CountColumn(vector<int> rows, int col)
{
	int count = 0;
	for (int i = 0; i < N; i++)
		if (rows[i] >> col & 1)
			count++;

	if (count > N / 2)
		count = N - count;

	return count;
}

void FlipRow(vector<int> rows, int row)
{
	if (row < N)
	{
		FlipRow(rows, row + 1);
		rows[row] = ~rows[row];
		FlipRow(rows, row + 1);
	}

	int count = 0;
	for (int i = 0; i < N; i++)
		count += CountColumn(rows, i);

	if (Min > count)
		Min = count;
}

int main()
{
	cin >> N;
	vector<int> Rows(N);
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		int one = 1;
		for (char c : str)
		{
			if (c == 'T')
				Rows[i] += one;
			one <<= 1;
		}
	}

	FlipRow(Rows, 0);
	cout << Min << "\n";
	return 0;
}
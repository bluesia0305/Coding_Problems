#include <iostream>

using namespace std;

int Paint(char board[][51], int m, int n)
{
	int count1 = 0, count2 = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2)
			{
				if (board[m + i][n + j] == 'B')
					count1++;
				else
					count2++;
			}
			else
			{
				if (board[m + i][n + j] == 'W')
					count1++;
				else
					count2++;
			}
		}

	return count1 > count2 ? count2 : count1;
}

int main()
{
	int M, N;
	cin >> M >> N;

	char ChessBoard[51][51] = { 0, };

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> ChessBoard[i][j];

	int MinPaint = 64;
	for (int i = 0; i < M - 7; i++)
		for (int j = 0; j < N - 7; j++)
		{
			int paint = Paint(ChessBoard, i, j);
			if (paint < MinPaint)
				MinPaint = paint;

			if (!MinPaint)
			{
				cout << "0\n";
				return 0;
			}
		}

	cout << MinPaint << "\n";
	return 0;
}
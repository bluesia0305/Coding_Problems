#include <iostream>

using namespace std;

int Paint(char board[][51], int m, int n)
{
	int count = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[m + i][n + j] == 'W' ^ ((i + j) & 1))
				count++;

	return count > 64 - count ? 64 - count : count;
}

int main()
{
	int M, N;
	cin >> M >> N;

	char ChessBoard[51][51] = { 0, };

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> ChessBoard[i][j];

	int result = 32;
	for (int i = 0; i < M - 7; i++)
		for (int j = 0; j < N - 7; j++)
		{
			int paint = Paint(ChessBoard, i, j);
			if (paint < result)
				result = paint;

			if (!result)
			{
				cout << "0\n";
				return 0;
			}
		}
	
	cout << result << "\n";
	return 0;
}
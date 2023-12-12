#include <iostream>

using namespace std;

int ChessBoard[12][12];
int Queens;
int Count;

void Print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ChessBoard[i][j] << " ";
        cout << "\n";
    }
    cout << "-------------------------\n";
}

void Queen(int n, int col, int inc)
{
    ChessBoard[Queens][col] += inc;
    if (Queens < n - 1)
    {
        int side = 1;
        for (int k = Queens + 1; k < n; k++)
        {
            ChessBoard[k][col] += inc;
            if (col - side >= 0)
                ChessBoard[k][col - side] += inc;
            if (col + side < n)
                ChessBoard[k][col + side] += inc;
            side++;
        }
    }
}

void PutQueen(int n)
{
    if (Queens < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (ChessBoard[Queens][i] == 0)
            {
                Queen(n, i, 1);
                Queens++;
                PutQueen(n);
                Queens--;
                Queen(n, i, -1);
            }
        }
    }
    else
        Count++;
}

int solution(int n)
{
    PutQueen(n);
    return Count;
}
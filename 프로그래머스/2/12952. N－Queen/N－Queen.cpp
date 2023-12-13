int ChessBoard[12][12];
int Queens;
int Count;

void AddQueen(int n, int col, int inc)
{
    // 퀸을 배치하는 곳 = ChessBoard[Queens][col]
    
    // 아래 방향 이동 경로 표시 (아래 방향 직선 및 왼쪽/오른쪽 대각선)
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

void PlayChess(int n)
{
    if (Queens == n)
    {
        Count++;
        return;
    }

    for (int i = 0; i < n; i++)
        if (ChessBoard[Queens][i] == 0)
        {
            AddQueen(n, i, 1);
            Queens++;
            PlayChess(n);
            Queens--;
            AddQueen(n, i, -1);
        }
}

int solution(int n)
{
    PlayChess(n);
    return Count;
}
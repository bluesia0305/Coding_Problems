#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int dir[3] = { -1, 0, 1 };
    const int n = board.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 1)
                for (int dx : dir)
                    for (int dy : dir)
                    {
                        if (i + dx >= 0 && i + dx < n &&
                            j + dy >= 0 && j + dy < n &&
                            board[i + dx][j + dy] == 0)
                            board[i + dx][j + dy] = 2;
                    }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 0)
                answer++;
    
    return answer;
}
#include <vector>

#define denom 1000000007

using namespace std;

int DP[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{   
    DP[1][0] = 1;
    for (vector<int> puddle : puddles)
        DP[puddle[1]][puddle[0]] = -1;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (DP[i][j] == 0)
            {
                if (DP[i][j - 1] > 0)
                    DP[i][j] += DP[i][j - 1];
                if (DP[i - 1][j] > 0)
                    DP[i][j] += DP[i - 1][j];
                DP[i][j] %= denom;
            }
    
    return DP[n][m] % denom;
}
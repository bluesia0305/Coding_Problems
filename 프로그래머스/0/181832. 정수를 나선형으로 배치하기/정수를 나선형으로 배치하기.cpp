#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int num = 1;
    int x = -1, y = 0, d = 1;
    
    while (num <= n * n)
    {
        while (x + d >= 0 && x + d < n && answer[y][x + d] == 0)
        {
            x += d;
            answer[y][x] = num++;
        }
    
        while (y + d >= 0 && y + d < n && answer[y + d][x] == 0)
        {
            y += d;
            answer[y][x] = num++;
        }
        d *= -1;
    }
    
    return answer;
}
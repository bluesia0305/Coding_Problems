#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#include <iostream>

int Map[100][100] = { 0, }; // 0 = visited, 'X' = sea
int LX, LY;

using namespace std;

void DFS(stack<int>& s, int x, int y)
{
    s.push(Map[y][x]);
    Map[y][x] = 0;
    
    if (x - 1 >= 0 && Map[y][x - 1] > 0 && Map[y][x - 1] != 'X')
        DFS(s, x - 1, y);
    
    if (x + 1 < LX && Map[y][x + 1] > 0 && Map[y][x + 1] != 'X')
        DFS(s, x + 1, y);
        
    if (y - 1 >= 0 && Map[y - 1][x] > 0 && Map[y - 1][x] != 'X')
        DFS(s, x, y - 1);
    
    if (y + 1 < LY && Map[y + 1][x] > 0 && Map[y + 1][x] != 'X')
        DFS(s, x, y + 1);
}

vector<int> solution(vector<string> maps)
{
    LX = maps[0].size();
    LY = maps.size();
    
    for (int y = 0; y < LY; y++)
        for (int x = 0; x < LX; x++)
            if (maps[y][x] != 'X')
                Map[y][x] = maps[y][x] - '0';
            else
                Map[y][x] = maps[y][x];
    
    vector<int> answer;
    for (int y = 0; y < LY; y++)
        for (int x = 0; x < LX; x++)
            if (Map[y][x] > 0 && Map[y][x] != 'X')
            {
                stack<int> s;
                DFS(s, x, y);
                int sum = 0;
                while (!s.empty())
                {
                    sum += s.top();
                    s.pop();
                }
                answer.push_back(sum);
            }
    
    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(),answer.end());
    
    return answer;
}
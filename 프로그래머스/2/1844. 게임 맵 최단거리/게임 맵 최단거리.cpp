#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int X;
    int Y;
    int Dist;
};

int LimitX = 0;
int LimitY = 0;
int DirX[4] = { 1, -1, 0, 0 };
int DirY[4] = { 0, 0, 1, -1 };

int solution(vector<vector<int>> maps)
{   
    LimitX = maps.size();
    LimitY = maps[0].size();
    
    queue<Point> q;
    q.push(Point{ 0, 0, 1 });
    
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();
        
        if (p.X == LimitX - 1 && p.Y == LimitY - 1)
            return p.Dist;
        
        for (int i = 0; i < 4; i++)
        {
            int x = p.X + DirX[i];
            int y = p.Y + DirY[i];
            
            if (x >= 0 && x < LimitX && y >= 0 && y < LimitY)
                if (maps[x][y])
                {
                    maps[x][y] = 0;
                    q.push(Point{ x, y, p.Dist + 1 });
                }
        }
    }
    
    return -1;
}
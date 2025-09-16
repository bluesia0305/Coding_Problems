#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots)
{
    int x1 = dots[0][0], x2 = dots[0][0], y1 = dots[0][1], y2 = dots[0][1];
    for (vector<int> v : dots)
    {
        if (x1 > v[0])
            x1 = v[0];
        if (x2 < v[0])
            x2 = v[0];
        if (y1 > v[1])
            y1 = v[1];
        if (y2 < v[1])
            y2 = v[1];
    }
    return (y2 - y1) * (x2 - x1);
}
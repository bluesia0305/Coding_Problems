#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Parent[100];

int Find(int a)
{
    int temp = a;
    while (a != Parent[a])
        a = Parent[a];
    return Parent[temp] = a;
}

void Union(int a, int b)
{
    if (Find(a) != Find(b))
        Parent[Parent[b]] = a;
}

int solution(int n, vector<vector<int>> costs)
{
    for (int i = 0; i < n; i++)
        Parent[i] = i;
    
    sort(costs.begin(),
         costs.end(),
         [](const vector<int>& a, const vector<int>& b)
         {
             return a[2] < b[2];
         });
    
    int answer = 0;
    for (vector<int> cost : costs)
    {
        if (Find(cost[0]) != Find(cost[1]))
        {
            Union(cost[0], cost[1]);
            answer += cost[2];
        }
    }
    
    return answer;
}
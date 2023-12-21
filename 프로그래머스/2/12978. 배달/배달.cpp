#include <iostream>
#include <vector>
using namespace std;

int Towns[51][51];

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j)
                Towns[i][j] = 99999999;
    
    for (vector<int> r : road)
        if (Towns[r[0]][r[1]] > r[2])
        {
            Towns[r[0]][r[1]] = r[2];    
            Towns[r[1]][r[0]] = r[2];
        }
    
    for (int w = 1; w <= N; w++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                int dist = Towns[i][w] + Towns[w][j];
                if (Towns[i][j] > dist)
                    Towns[i][j] = dist;
            }

    for (int i = 1; i <= N; i++)
        if (Towns[1][i] <= K)
            answer++;
    
    return answer;
}
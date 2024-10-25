#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int maxVal = 0;
            for (int k = 0; k < 4; k++)
            {
                if (j != k &&
                    maxVal < land[i - 1][k])
                    maxVal = land[i - 1][k];
            }
            land[i][j] += maxVal;
        }
    }
    
    int answer = 0;
    for (int k = 0; k < 4; k++)
        if (answer < land[land.size() - 1][k])
            answer = land[land.size() - 1][k];

    return answer;
}
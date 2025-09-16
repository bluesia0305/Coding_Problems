#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance)
{
    int answer = 0;
    int coef = 10000;
    int r = 1;
    int count = 0;
    while (count < 3)
    {
        int idx = 0;
        for (; idx < rank.size(); idx++)
            if (rank[idx] == r)
                break;
        
        if (attendance[idx])
        {
            answer += idx * coef;
            count++;
            coef /= 100;
        }
            
        r++;
    }

    return answer;
}
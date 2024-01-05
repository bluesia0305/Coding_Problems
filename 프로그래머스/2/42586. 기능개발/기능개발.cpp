#include <vector>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    const int n = progresses.size();
    queue<int> remains;
    for (int i = 0; i < n; i++)
    {
        int r = 100 - progresses[i];
        remains.emplace(r / speeds[i] + (r % speeds[i] ? 1 : 0));
    }
    
    vector<int> answer;
    int day = remains.front();
    int num = 0;
    while (!remains.empty())
    {
        int release = remains.front();
        remains.pop();
        
        if (day < release)
        {
            day = release;
            answer.push_back(num);
            num = 0;
        }
        num++;
    }
    
    if (num)
        answer.push_back(num);
    
    return answer;
}
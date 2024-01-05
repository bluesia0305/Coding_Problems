#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int day = 0;
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = (99 - progresses[i]) / speeds[i] + 1;
        if (day < remain)
        {
            day = remain;
            answer.push_back(1);
        }
        else
            answer.back()++;
    }
    
    return answer;
}
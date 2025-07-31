#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int num, int total)
{
    vector<int> answer;
    int sum = 0;
    for (int i = total / num; i < total / num + num; i++)
    {
        answer.push_back(i);
        sum += i;
    }
    
    while (sum < total)
    {
        sum -= answer.front();
        answer.erase(answer.begin());

        sum += answer.back() + 1;
        answer.push_back(answer.back() + 1);
    }
    
    sort(answer.begin(), answer.end(), greater());
    while (sum > total)
    {
        sum -= answer.front();
        answer.erase(answer.begin());

        sum += answer.back() - 1;
        answer.push_back(answer.back() - 1);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
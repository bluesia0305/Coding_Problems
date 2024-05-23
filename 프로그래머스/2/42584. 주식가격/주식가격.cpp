#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int num = prices.size();
    vector<int> answer(num);
    stack<int> s;
    s.push(0);
    
    for (int i = 1; i < num; i++)
    {
        int l = s.top();
        while (!s.empty() && prices[i] < prices[l])
        {
            answer[l] = i - l;
            s.pop();
            l = s.top();
        }
        
        s.push(i);
    }
    
    while (!s.empty())
    {
        int n = s.top();
        s.pop();
        
        answer[n] = num - n - 1;
    }
    
    return answer;
}
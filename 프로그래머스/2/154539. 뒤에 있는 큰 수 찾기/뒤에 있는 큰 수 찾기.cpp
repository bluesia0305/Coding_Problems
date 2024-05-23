#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size());
    
    stack<int> s;
    s.push(0);
    
    for (int i = 0; i < numbers.size(); i++)
    {
        while (!s.empty() && numbers[i] > numbers[s.top()])
        {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        
        s.push(i);
    }
    
    while (!s.empty())
    {
        answer[s.top()] = -1;
        s.pop();
    }
    
    return answer;
}
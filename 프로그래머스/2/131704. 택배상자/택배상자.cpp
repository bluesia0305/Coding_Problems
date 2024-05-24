#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    int answer = 0;
    stack<int> Sub;
    for (int box = 1; box <= order.size(); box++)
    {
        Sub.push(box);
        
        while (!Sub.empty() && Sub.top() == order[answer])
        {            
            Sub.pop();
            answer++;
        }
    }
    
    return answer;
}
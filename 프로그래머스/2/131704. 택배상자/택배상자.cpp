#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    int answer = 0;
    int box = 1;
    stack<int> Sub;
    for (int i = 0; i < order.size(); i++)
    {
        while (!Sub.empty())
        {            
            if (Sub.top() == order[i])
            {
                Sub.pop();
                answer++;
                i++;
            }
            else
                break;
        }
        
        while (box < order.size() && box != order[i])
            Sub.push(box++);

        if (box == order[i])
        {
            box++;
            answer++;
        }
        else
            break;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString)
{
    vector<int> answer;
    int n = 0;
    
    for (int i = 0; i < myString.size(); i++)
    {
        if (myString[i] == 'x')
        {
            answer.push_back(n);
            n = 0;
        }
        else
            n++;
        
        if (i == myString.size() - 1)
            answer.push_back(n);
    }
    
    return answer;
}
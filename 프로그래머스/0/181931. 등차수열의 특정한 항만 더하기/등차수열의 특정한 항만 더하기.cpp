#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included)
{
    int answer = included[0] ? a : 0;
    int term = a;
    
    if (included.size() == 1)
        return answer;
    
    for (int i = 1; i < included.size(); i++)
    {
        term += d;
        if (included[i])
            answer += term;
    }
        
    return answer;
}
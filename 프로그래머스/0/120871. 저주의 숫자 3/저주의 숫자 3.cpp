#include <string>
#include <vector>

using namespace std;

bool isCursed(int n)
{
    if (!(n % 3))
        return true;

    for (char c : to_string(n))
        if (c == '3')
            return true;
    
    return false;
}

int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer++;
        while (isCursed(answer))
            answer++;
    }
        
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int n1 = 1;
    int n2 = 2;
    
    if (n < 3)
        return n;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            answer = n1 + n2;
            answer %= 1000000007;
            
            n1 = n2;
            n2 = answer;
        }
    }
    
    return answer;
}
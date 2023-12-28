#include <string>

using namespace std;

int solution(int n)
{
    if (n == 2)
        return 1;
    
    int answer, a = 1, b = 1;
    for (int i = 3; i <= n; i++)
    {
        answer = (a + b) % 1234567;
        a = b;
        b = answer;
    }
    
    return answer;
}
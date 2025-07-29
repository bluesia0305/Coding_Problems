#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c)
{
    int answer = a + b + c;
    
    if (a != b && b != c && c != a)
        return answer;
    else
    {
        answer *= (a*a + b*b + c*c);
        
        if (a == b && b == c)
            return answer *= (a*a*a + b*b*b + c*c*c);
        else
            return answer;
    }
}
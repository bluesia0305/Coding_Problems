#include <string>
#include <vector>

using namespace std;

string solution(string a, string b)
{
    string answer = "";
    
    int len = a.size() < b.size() ? b.size() : a.size();
    int up = 0;
    for (int i = 0; i < len; i++)
    {
        int n1 = 0, n2 = 0;
        if (i < a.size())
            n1 = a[a.size() - 1 - i] - '0';
        if (i < b.size())
            n2 = b[b.size() - 1 - i] - '0';
        
        int digit = n1 + n2 + up;
        up = 0;
        
        if (digit >= 10)
        {
            digit -= 10;
            up = 1;
        }
        
        answer = to_string(digit) + answer;
    }
    
    if (up)
        answer = "1" + answer;
    
    return answer;
}
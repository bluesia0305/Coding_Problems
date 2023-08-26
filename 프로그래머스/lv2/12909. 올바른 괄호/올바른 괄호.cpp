#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    if (s[0] == ')')
        return false;
    
    int flag = 0;
    for (char c : s)
    {
        flag += (c == '(' ? 1 : -1);
        if (flag < 0)
            return false;
    }
         

    return flag == 0;
}
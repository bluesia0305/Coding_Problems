#include <string>

using namespace std;

bool solution(string s)
{
    int flag = 0;
    for (char c : s)
    {
        flag += (c == '(' ? 1 : -1);
        if (flag < 0)
            return false;
    }

    return flag == 0;
}
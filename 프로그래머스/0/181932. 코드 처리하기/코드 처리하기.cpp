#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    string answer = "";
    int mode = 1;
    for (int i = 0; i < code.size(); i++)
    {
        string s = code.substr(i, 1);
        if (s == "1")
        {
            mode *= -1;
            continue;
        }
        
        if (mode == 1)
        {
            if (!(i % 2))
                answer += s;
        }
        else
        {
            if (i % 2)
                answer += s;
        }
    }
    
    return answer == "" ? "EMPTY" : answer;
}
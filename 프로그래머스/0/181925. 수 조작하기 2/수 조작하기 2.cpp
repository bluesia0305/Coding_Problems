#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog)
{
    string answer = "";
    int curr = numLog[0];
    for (int i = 1; i < numLog.size(); i++)
    {
        switch (numLog[i] - curr)
        {
            case   1: answer += "w"; break;
            case  -1: answer += "s"; break;
            case  10: answer += "d"; break;
            case -10: answer += "a"; break;
        }
        curr = numLog[i];
    }
    return answer;
}
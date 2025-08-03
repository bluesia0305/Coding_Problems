#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat)
{
    for (int i = myString.size() - pat.size(); i >= 0; i--)
    {
        if (myString.substr(i, pat.size()) == pat)
            return myString.substr(0, i + pat.size());
    }
    
    return "";
}
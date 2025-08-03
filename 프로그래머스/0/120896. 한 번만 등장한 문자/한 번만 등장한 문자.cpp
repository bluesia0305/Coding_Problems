#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s)
{
    map<char, int> m;
    for (char c : s)
        m[c]++;
    
    string answer = "";
    for (pair<char, int> p : m)
    {
        if (p.second == 1)
        {
            string str(1, p.first);
            answer += str;
        }
    }
    return answer;
}
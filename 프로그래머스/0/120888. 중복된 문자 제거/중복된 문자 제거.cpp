#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string)
{
    string answer = "";
    unordered_set<char> uset;
    
    for (char c : my_string)
    {
        auto p = uset.emplace(c);
        if (p.second)
        {
            string str(1, c);
            answer += str;
        }
    }
            
    return answer;
}
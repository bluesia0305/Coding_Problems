#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
    map<char, int> m;
    for (string s : spell)
        m[s[0]]++;
    
    for (string s : dic)
    {
        map<char, int> comp;
        for (char c : s)
            comp[c]++;
        
        if (comp == m)
            return 1;
    }
    
    return 2;
}
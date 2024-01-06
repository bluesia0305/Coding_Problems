#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool ischar(char c)
{
    if ('a' <= c && c <= 'z')
        return true;
    
    return false;
}

int solution(string str1, string str2)
{
    for (char& c : str1)
        c = tolower(c);
    
    for (char& c : str2)
        c = tolower(c);
    
    unordered_map<string, int> pairs1, pairs2;
    unordered_set<string> pairs;
    for (int i = 0; i < str1.size() - 1; i++)
        if (ischar(str1[i]) && ischar(str1[i + 1]))
        {
            pairs1[str1.substr(i, 2)]++;
            pairs.emplace(str1.substr(i, 2));
        }
    
    for (int i = 0; i < str2.size() - 1; i++)
        if (ischar(str2[i]) && ischar(str2[i + 1]))
        {
            pairs2[str2.substr(i, 2)]++;
            pairs.emplace(str2.substr(i, 2));
        }
    
    int a = 0, b = 0;
    for (auto& s : pairs)
    {
        a += min(pairs1[s], pairs2[s]);
        b += max(pairs1[s], pairs2[s]);
    }

    if (b)
        return int(float(a) / b * 65536);
    else
        return 65536;
}
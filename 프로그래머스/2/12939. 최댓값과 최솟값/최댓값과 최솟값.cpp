#include <string>

using namespace std;

string solution(string s)
{
    int min = 2147483647;
    int max = -2147483648;
    
    while (s.size() > 0)
    {
        int end = 0;
        while (s[end] != ' ' && end != s.size() - 1)
            end++;
        
        int n = stoi(s.substr(0, end + 1));
            
        if (min > n)
            min = n;
            
        if (max < n)
            max = n;
            
        s = s.substr(end + 1);
    }
    
    return to_string(min) + " " + to_string(max);
}
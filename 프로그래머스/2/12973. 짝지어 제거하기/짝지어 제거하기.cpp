#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    if (s.size() % 2)
        return 0;
    
    stack<char> words;
    
    for (char c : s)
    {
        if (!words.empty() && words.top() == c)
            words.pop();
        else
            words.push(c);
    }
    
    return words.empty();
}
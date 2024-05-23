#include <string>
#include <vector>
#include <deque>

#include <iostream>

using namespace std;

string solution(string number, int k)
{
    int i = 0;
    int del = 0;
    deque<char> s;
    while (i < number.size())
    {
        while (del < k && !s.empty() && s.back() < number[i])
        {
            s.pop_back();
            del++;
        }
        
        s.push_back(number[i++]);
    }
    
    while (del < k)
    {
        s.pop_back();
        del++;
    }
    
    string str(s.begin(), s.end());
    return str;
}
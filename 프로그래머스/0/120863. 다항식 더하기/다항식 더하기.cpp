#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string polynomial)
{
    istringstream ss(polynomial);
    string buffer;
    int coefficient = 0;
    int constant = 0;
    while (getline(ss, buffer, ' '))
    {
        if (buffer == "+")
            continue;
        
        if (buffer.back() == 'x')
        {
            string s = buffer.substr(0, buffer.size() - 1);
            coefficient += s == "" ? 1 : stoi(s);
        }
        else
            constant += stoi(buffer);
    }
    
    if (coefficient == 0)
        return to_string(constant);
    else
    {
        string prefix = (coefficient == 1 ? "" : to_string(coefficient)) + "x";
        if (constant == 0)
            return prefix;
        else
            return prefix + " + " + to_string(constant);
    }
}
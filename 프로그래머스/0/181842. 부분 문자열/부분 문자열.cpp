#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2)
{
    if (str1.size() > str2.size())
        return 0;
    
    for (int i = 0; i <= str2.size() - str1.size(); i++)
        if (str1 == str2.substr(i, str1.size()))
            return 1;
    
    return 0;
}
#include <string>

using namespace std;

int solution(string my_string, string target)
{
    if (target.size() <= my_string.size())
        for (int i = 0; i <= my_string.size() - target.size(); i++)
            if (target == my_string.substr(i, target.size()))
                return 1;
        
    return 0;
}
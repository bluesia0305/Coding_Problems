#include <string>
#include <vector>

using namespace std;

string solution(string rny_string)
{
    auto i = rny_string.find("m");
    while (i < rny_string.size())
    {
        rny_string.replace(i, 1, "rn");
        i = rny_string.find("m");
    }
    
    return rny_string;
}
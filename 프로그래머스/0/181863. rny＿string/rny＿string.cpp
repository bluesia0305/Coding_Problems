#include <string>

using namespace std;

string solution(string rny_string)
{
    auto i = rny_string.find("m");
    while (i != string::npos)
    {
        rny_string.replace(i, 1, "rn");
        i = rny_string.find("m");
    }
    
    return rny_string;
}
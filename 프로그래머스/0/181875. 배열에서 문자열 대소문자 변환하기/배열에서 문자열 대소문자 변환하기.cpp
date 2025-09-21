#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    for (int i = 0; i < strArr.size(); i++)
        for (char& c : strArr[i])
        {
            if (i % 2)
                c = toupper(c);
            else
                c = tolower(c);
        }
    
    return strArr;
}
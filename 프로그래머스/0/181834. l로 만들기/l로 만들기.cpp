#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    for (char& c : myString)
        if (c < 'l')
            c = 'l';
    return myString;
}
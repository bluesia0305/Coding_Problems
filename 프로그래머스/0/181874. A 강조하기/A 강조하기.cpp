#include <string>

using namespace std;

string solution(string myString)
{
    for (char& c : myString)
    {
        if (c == 'a')
            c = toupper(c);
        else if (c != 'A')
            c = tolower(c);
    }
    
    return myString;
}
#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    for (char& c : myString)
        if (c == 'A')
            c += 1;
        else
            c -= 1;
    
    int answer = myString.find(pat);
    if (answer != string::npos)
        return 1;
    else
        return 0;
}
#include <string>
#include <algorithm>

using namespace std;

int pairs1[676];
int pairs2[676];

int solution(string str1, string str2)
{
    for (int i = 0; i < str1.size() - 1; i++)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            pairs1[(str1[i] & 31) * 26 + (str1[i + 1] & 31)]++;
        
    for (int i = 0; i < str2.size() - 1; i++)
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            pairs2[(str2[i] & 31) * 26 + (str2[i + 1] & 31)]++;
    
    int a = 0, b = 0;
    for (int i = 0; i < 676; i++)
    {
        a += min(pairs1[i], pairs2[i]);
        b += max(pairs1[i], pairs2[i]);
    }
    
    return b ? a * 65536 / b : 65536;
}
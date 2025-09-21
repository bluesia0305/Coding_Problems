#include <string>
#include <vector>

using namespace std;

int solution(int num, int k)
{
    string nstr = to_string(num);
    for (int i = 0; i < nstr.size(); i++)
    {
        if (nstr[i] == k + '0')
            return i + 1;
    }
    return -1;
}
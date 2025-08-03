#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int prod = 1;
    int i = 1;
    while (true)
    {
        if (prod > n)
            return i - 1;

        prod *= ++i;
    }
}
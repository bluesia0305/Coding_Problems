#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 0;
    if ((a * b) % 2)
        return a * a + b * b;
    else
    {
        if (!(a % 2) && !(b % 2))
            return a > b ? a - b : b - a;
        else
            return 2 * (a + b);
    }
}
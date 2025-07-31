#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){ return b ? GCD(b, (a % b)) : a; }

int solution(int a, int b)
{
    int g = GCD(a, b);
    a /= g;
    b /= g;
    
    while (!(b % 2))
        b /= 2;
    
    while (!(b % 5))
        b /= 5;
    
    return b == 1 ? 1 : 2;
}
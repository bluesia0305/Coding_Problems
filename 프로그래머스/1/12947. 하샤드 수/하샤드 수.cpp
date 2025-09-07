#include <string>
#include <vector>

using namespace std;

bool solution(int x)
{
    string s = to_string(x);
    int sum = 0;
    for (char c : s)
        sum += c - '0';
    return x % sum ? false : true;
}
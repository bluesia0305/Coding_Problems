#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides)
{
    return sides[0] < sides[1] ? 2 * sides[0] - 1 : 2 * sides[1] - 1;
}
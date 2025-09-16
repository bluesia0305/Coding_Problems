#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides)
{
    int sum = sides[0] + sides[1];
    int longer = sides[0] > sides[1] ? sides[0] : sides[1];
    int shorter = sides[0] > sides[1] ? sides[1] : sides[0];

    return sum - 1 - longer + shorter;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());
    int a = numbers[0] * numbers[1];
    int b = numbers[numbers.size() - 2] * numbers[numbers.size() - 1];
    return a > b ? a : b;
}
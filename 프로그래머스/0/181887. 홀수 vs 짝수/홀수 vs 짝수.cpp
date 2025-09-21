#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> num_list)
{
    int sumOdd = 0, sumEven = 0;
    int answer = 0;
    for (int i = 0; i < num_list.size(); i += 2)
        sumOdd += num_list[i];
    for (int i = 1; i < num_list.size(); i += 2)
        sumEven += num_list[i];
    return max(sumOdd, sumEven);
}
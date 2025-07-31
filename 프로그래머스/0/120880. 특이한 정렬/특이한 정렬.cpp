#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n)
{
    vector<int> answer(numlist);
    sort(answer.begin(), answer.end(),
         [=](const int& a, const int& b)
         {
             if (abs(a - n) == abs(b - n))
                 return a > b;
             else
                 return abs(a - n) < abs(b - n);
         });
    return answer;
}
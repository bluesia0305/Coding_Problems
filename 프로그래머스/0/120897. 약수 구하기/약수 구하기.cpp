#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    for (int i = 1; i <= sqrt(n); i++)
        if (!(n % i))
        {
            if (i == n / i)
                answer.push_back(i);
            else
            {
                answer.push_back(i);
                answer.push_back(n / i);
            }
        }
    
    sort(answer.begin(), answer.end());
    return answer;
}
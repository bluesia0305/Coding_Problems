#include <vector>

using namespace std;

void Add(const vector<int>& v, const int& t, int& cnt, int i, int sum)
{
    if (i == v.size())
    {
        if (t == sum)
            cnt++;
        return;
    }
    
    Add(v, t, cnt, i + 1, sum + v[i]);
    Add(v, t, cnt, i + 1, sum - v[i]);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    Add(numbers, target, answer, 1,  numbers[0]);
    Add(numbers, target, answer, 1, -numbers[0]);
    return answer;
}
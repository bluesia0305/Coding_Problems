#include <string>
#include <vector>

using namespace std;

void Add(const vector<int>& v, int size, int& cnt, int i, int t, int sum)
{
    if (i == size)
    {
        if (t == sum)
            cnt++;
        return;
    }
    
    Add(v, size, cnt, i + 1, t, sum + v[i]);
    Add(v, size, cnt, i + 1, t, sum - v[i]);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    Add(numbers, numbers.size(), answer, 1, target, numbers[0]);
    Add(numbers, numbers.size(), answer, 1, target, -numbers[0]);
    return answer;
}
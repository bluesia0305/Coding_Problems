#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<>());
    
    int r = people.size() - 1;
    for (int f = 0; f <= r; f++)
    {
        answer++;
        if (f == r)
            break;
        
        if (people[f] + people[r] <= limit)
            r--;
    }
    
    return answer;
}
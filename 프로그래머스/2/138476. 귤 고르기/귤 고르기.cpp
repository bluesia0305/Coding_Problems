#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    unordered_map<int, int> partition;
    
    for (int n : tangerine)
        partition[n]++;
    
    vector<pair<int, int>> sorted(partition.begin(), partition.end());
    sort(sorted.begin(),
         sorted.end(),
         [](const pair<int, int>& a, const pair<int, int>& b)
         {
             return a.second > b.second;
         });
    
    int sum = 0, answer = 0;
    for (pair<int, int> p : sorted)
    {
        sum += p.second;
        answer++;
        if (sum >= k)
            break;
    }
    
    return answer;
}
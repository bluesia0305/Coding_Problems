#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int answer = 0;
    while (true)
    {
        if (pq.top() >= K)
            return answer;
        
        if (pq.size() == 1 && pq.top() < K)
            return -1;
        
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        
        pq.push(min1 + 2 * min2);
        answer++;
    }
    
    return answer;
}
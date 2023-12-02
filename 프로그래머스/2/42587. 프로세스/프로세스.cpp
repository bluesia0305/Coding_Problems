#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    int tgt_priority = priorities[location];
    int max_priority = 0;
    
    while (true)
    {
        if (max_priority == 0)
            for (int n : priorities)
                if (max_priority < n)
                    max_priority = n;

        int front = priorities[0];
        priorities.erase(priorities.begin());
        if (front == max_priority)
        {
            answer++;
            if (location == 0)
                break;
            
            max_priority = 0;
        }
        else
            priorities.push_back(front);
        
        if (--location < 0)
            location += priorities.size();
    }
        
    return answer;
}
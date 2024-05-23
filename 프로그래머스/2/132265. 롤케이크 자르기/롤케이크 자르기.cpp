#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;
    
    map<int, int> left;
    map<int, int> right;
    for (auto& n : topping)
        right[n]++;
    
    for (auto& n : topping)
    {
        right[n]--;
        if (right[n] == 0)
            right.erase(n);
        
        left[n]++;
        
        if (left.size() == right.size())
            answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> items;
    for (int i = 0; i < 9; i++)
        items[discount[i]]++;

    for (int i = 9; i < discount.size(); i++)
    {
        items[discount[i]]++;
        
        bool bSatisfied = true;
        for (int i = 0; i < want.size(); i++)
            if (items[want[i]] != number[i])
            {
                bSatisfied = false;
                break;
            }
        
        if (bSatisfied)
            answer++;
        
        items[discount[i - 9]]--;
    }
    
    return answer;
}
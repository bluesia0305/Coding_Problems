#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int sum = 0, answer = 0;
    unordered_map<string, int> items;
    for (int i = 0; i < want.size(); i++)
    {
        items[want[i]] = number[i];
        sum += number[i];
    }

    queue<string> q;
    for (string item : discount)
    {
        if (find(want.begin(), want.end(), item) != want.end())
        {
            items[item]--;
            sum--;
            q.emplace(item);
            
            while (items[item] < 0)
            {
                items[q.front()]++;
                sum++;
                q.pop();
            }
        }
        else
        {
            while (!q.empty())
            {
                items[q.front()]++;
                sum++;
                q.pop();
            }
        }
        
        if (sum == 0)
            answer++;
    }
    return answer;
}
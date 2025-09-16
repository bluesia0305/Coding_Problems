#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    map<vector<int>, int> map;
    vector<vector<int>> sorted = score;
    sort(sorted.begin(), sorted.end(),
         [](const vector<int>& a, const vector<int>& b)
         {
             return a[0] + a[1] > b[0] + b[1];
         });
    
    for (int i = 0; i < sorted.size(); i++)
    {
        map[sorted[i]] = i + 1;
        
        if (i > 0)
            if (sorted[i][0] + sorted[i][1] == sorted[i - 1][0] + sorted[i - 1][1])
                map[sorted[i]] = map[sorted[i - 1]];
    }
    
    vector<int> answer(score.size());
    for (int i = 0; i < score.size(); i++)
        answer[i] = map[score[i]];
        
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<int> answer(score.size());
    for (vector<int>& v : score)
        v.push_back(v[0] + v[1]);
    
    for (vector<int> v : score)
        for (int i = 0; i < score.size(); i++)
            if (v[2] > score[i][2])
                answer[i]++;
    
    for (int& a : answer)
        a++;
    
    return answer;
}
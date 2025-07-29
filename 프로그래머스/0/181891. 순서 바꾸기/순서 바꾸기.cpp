#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> answer = num_list;
    int i = 0;
    
    while (i < n)
    {
        answer.push_back(answer.front());
        answer.erase(answer.begin());
        i++;
    }
    
    return answer;
}
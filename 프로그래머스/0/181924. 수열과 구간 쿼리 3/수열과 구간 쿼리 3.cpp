#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer = arr;    
    for (vector<int> v : queries)
    {
        int temp = answer[v[0]];
        answer[v[0]] = answer[v[1]];
        answer[v[1]] = temp;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer = arr;
    for (vector<int> query : queries)
        for (int i = query[0]; i <= query[1]; i++)
            answer[i]++;
    
    return answer;
}
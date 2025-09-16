#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer;
    for (vector<int> query : queries)
    {
        int num = 1000001;
        for (int i = query[0]; i <= query[1]; i++)
        {
            if (arr[i] > query[2] && arr[i] < num)
                num = arr[i];
        }
        answer.push_back(num == 1000001 ? -1 : num);
    }
    return answer;
}
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string)
{
    vector<int> answer;
    
    for (int i = 0; i < my_string.length(); i++)
    {
        char w = my_string[i];
        if (w >= '0' && w <= '9')
            answer.push_back(w - '0');
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num)
{
    vector<int> answer;
    int n = start_num;
    
    while (n >= end_num)
    {
        answer.push_back(n);
        n--;
    }
    
    return answer;
}
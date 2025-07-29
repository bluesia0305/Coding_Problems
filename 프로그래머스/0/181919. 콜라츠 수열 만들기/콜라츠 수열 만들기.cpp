#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    
    int num = n;
    while (num > 1)
    {
        answer.push_back(num);
        
        if (num % 2)
            num = 3 * num + 1;
        else
            num /= 2;
    }
    
    answer.push_back(1);
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist)
{
    vector<int> answer;
    for (int num : numlist)
        if (!(num % n))
            answer.push_back(num);
    
    return answer;
}
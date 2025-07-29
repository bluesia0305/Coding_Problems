#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n)
{
    int answer = 0;
    for (int num : numbers)
        if (answer <= n)
            answer += num;
    
    return answer;
}
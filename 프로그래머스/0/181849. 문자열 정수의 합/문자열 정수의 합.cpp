#include <string>

using namespace std;

int solution(string num_str)
{
    int answer = 0;
    for (char s : num_str)
        answer += s - '0';
    
    return answer;
}
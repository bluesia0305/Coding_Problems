#include <string>
#include <vector>

using namespace std;

int solution(string A, string B)
{
    int answer = 0;
    string ori = A;
    
    while (true)
    {
        if (A == B)
            return answer;
        
        A = A.back() + A.substr(0, A.size() - 1);
        if (A == ori)
            return -1;
        
        answer++;
    }
}
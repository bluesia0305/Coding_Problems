#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common)
{
    int answer = 0;
    
    if (common[1] - common[0] == common[2] - common[1])
        return common.back() + common[1] - common[0];
    else
        return common.back() * common[1] / common[0];
}
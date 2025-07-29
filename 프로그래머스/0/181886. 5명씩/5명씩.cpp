#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names)
{
    vector<string> answer;
    for (int i = 1; i <= names.size(); i++)
        if (i % 5 == 1)
            answer.push_back(names[i - 1]);
    
    return answer;
}
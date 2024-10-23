#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    int start = 0, end = 0;
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string.substr(i, 1) == " ")
        {
            if (end > start)
            {
                answer.push_back(my_string.substr(start, end - start));
                start = end + 1;
            }
            else
                start++;
        }
        end++;
    }
    
    if (end > start)
        answer.push_back(my_string.substr(start, end - start));
                    
    return answer;
}
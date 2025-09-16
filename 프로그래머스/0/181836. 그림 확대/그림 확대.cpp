#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k)
{
    vector<string> answer;
    for (int i = 0; i < picture.size(); i++)
    {
        string line = "";
        for (char c : picture[i])
        {
            string s = "0";
            s[0] = c;
            for (int j = 0; j < k; j++)
                line += s;
        }
        
        for (int j = 0; j < k; j++)
            answer.push_back(line);
    }
    return answer;
}
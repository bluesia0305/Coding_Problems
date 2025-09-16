#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    for (vector<string> v : db)
    {
        if (v[0] == id_pw[0])
        {
            if (v[1] == id_pw[1])
                return "login";
            else
                return "wrong pw";
        }
    }
    return "fail";
}
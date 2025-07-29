#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code)
{
    string answer = "";
    for (int i = 1; i <= cipher.size(); i++)
        if (!(i % code))
            answer += cipher.substr(i - 1, 1);
        
    return answer;
}
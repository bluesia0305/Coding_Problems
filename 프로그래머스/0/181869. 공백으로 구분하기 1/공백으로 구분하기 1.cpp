#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    string str = "";
    stringstream ss(my_string);
    while (ss >> str)
        answer.push_back(str);
    
    return answer;
}
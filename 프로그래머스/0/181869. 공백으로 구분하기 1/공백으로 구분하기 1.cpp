#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    string sout;
    stringstream ss(my_string);
    while (ss >> sout)
        answer.push_back(sout);
    
    return answer;
}
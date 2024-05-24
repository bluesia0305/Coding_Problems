#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end(),
         [](const int& a, const int& b)
         {
             string strA = to_string(a);
             string strB = to_string(b);
             return stoi(strA + strB) > stoi(strB + strA);
         });
    
    string answer = "";
    for (int& n : numbers)
        answer += to_string(n);

        return answer[0] == '0' ? "0" : answer;
}
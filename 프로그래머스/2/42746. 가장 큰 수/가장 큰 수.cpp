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
    bool Zero = true;
    for (int& n : numbers)
    {
        if (n > 0)
            Zero = false;
        answer += to_string(n);
    }
    
    if (Zero)
        return "0";
    else
        return answer;
}
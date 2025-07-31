#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void MakeNumbers(vector<int>& v, int l, int r, string s)
{
    if (s.size() > 6)
        return;
    
    if (stoi(s) >= l && stoi(s) <= r)
        v.push_back(stoi(s));
    
    MakeNumbers(v, l, r, s + "0");
    MakeNumbers(v, l, r, s + "5");
}

vector<int> solution(int l, int r)
{
    vector<int> answer;
    MakeNumbers(answer, l, r, "5");
    sort(answer.begin(), answer.end());
    
    if (answer.size() == 0)
        answer.push_back(-1);
    
    return answer;
}
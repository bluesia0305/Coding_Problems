#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Move(int num, int from, int dest, int via)
{
    if (num == 1)
    {
        vector<int> v;
        v.push_back(from);
        v.push_back(dest);
        answer.push_back(v);
    }
    else
    {
        Move(num - 1, from, via, dest);
        Move(1, from, dest, via);
        Move(num - 1, via, dest, from);
    }
}

vector<vector<int>> solution(int n)
{
    Move(n, 1, 3, 2);
    return answer;
}
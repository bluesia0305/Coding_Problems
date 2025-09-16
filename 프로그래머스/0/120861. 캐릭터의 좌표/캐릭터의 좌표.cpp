#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> answer = { 0, 0 };
    vector<int> size = { (board[0] - 1) / 2, (board[1] - 1) / 2 };
    for (string s : keyinput)
    {
        if (s == "left")
        {
            if (answer[0] > -size[0])
                answer[0]--;
            continue;
        }
        if (s == "right")
        {
            if (answer[0] < size[0])
                answer[0]++;
            continue;
        }
        if (s == "up")
        {
            if (answer[1] < size[1])
                answer[1]++;
            continue;
        }
        if (s == "down")
        {
            if (answer[1] > -size[1])
                answer[1]--;
            continue;
        }
    }
    
    return answer;
}
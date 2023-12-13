#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2);

    int innerRow = 1;    
    while (true)
    {
        int innerCol = yellow / innerRow;
        if (innerRow * innerCol == yellow)
        {
            if (2 * innerRow + 2 * innerCol + 4 == brown)
            {
                answer[0] = innerCol + 2;
                answer[1] = innerRow + 2;
                break;
            }
        }

        innerRow++;
        continue;
    }
    
    return answer;
}
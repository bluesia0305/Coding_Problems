#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    long long row = left / n, col = left % n;
    for (long long i = left; i <= right; i++)
    {
        answer.push_back(row < col ? col + 1 : row + 1);
        if (++col == n)
        {
            row++;
            col = 0;
        }
    }
    
    return answer;
}
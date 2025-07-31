#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines)
{
    int overlaps[200] = { 0, };
    for (vector<int> line : lines)
        for (int i = line[0] + 100; i < line[1] + 100; i++)
            overlaps[i]++;
    
    int answer = 0;
    for (int n : overlaps)
        if (n > 1)
            answer++;
    return answer;
}
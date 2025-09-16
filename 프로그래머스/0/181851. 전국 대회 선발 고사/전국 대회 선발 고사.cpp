#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance)
{
    vector<vector<int>> students;
    for (int i = 0; i < rank.size(); i++)
        if (attendance[i]) students.push_back(vector<int>{ i, rank[i] });
    
    sort(students.begin(), students.end(),
         [](const vector<int>& a, const vector<int>& b)
         {
             return a[1] < b[1];
         });
    
    return students[0][0] * 10000 + students[1][0] * 100 + students[2][0];
}
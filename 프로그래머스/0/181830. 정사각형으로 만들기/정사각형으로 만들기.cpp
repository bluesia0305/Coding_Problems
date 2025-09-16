#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    
    int n = 0;
    if (rows > cols)
    {
        n = rows - cols;
        for (vector<int>& v : arr)
            for (int i = 0; i < n; i++)
                v.push_back(0);
    }
    else if (rows < cols)
    {
        n = cols - rows;
        vector<int> v(cols);
        for (int i = 0; i < n; i++)
            arr.push_back(v);
    }

    return arr;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    for (int n : delete_list)
    {
        auto iter = find(arr.begin(), arr.end(), n);
        if (iter != arr.end())
            arr.erase(iter);
    }
    
    return arr;
}
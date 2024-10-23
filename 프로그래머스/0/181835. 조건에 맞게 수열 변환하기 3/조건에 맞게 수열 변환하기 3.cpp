#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    if (k % 2)
        for (int& num : arr)
            num *= k;
    else
        for (int& num : arr)
            num += k;
    
    return arr;
}
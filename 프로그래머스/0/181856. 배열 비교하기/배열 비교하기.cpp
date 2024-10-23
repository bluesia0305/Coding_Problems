#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2)
{
    if (arr1.size() > arr2.size())
        return 1;
    else if (arr1.size() < arr2.size())
        return -1;
    else
    {
        int n1 = 0;
        for (const int& n : arr1)
            n1 += n;
        
        int n2 = 0;
        for (const int& n : arr2)
            n2 += n;
        
        if (n1 > n2)
            return 1;
        else if (n1 < n2)
            return -1;
        else
            return 0;
    }
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n)
{
    for (const int& num : num_list)
        if (num == n)
            return 1;
    
    return 0;
}
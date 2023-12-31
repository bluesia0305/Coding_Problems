#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements)
{
    unordered_set<int> nums;
    for (int i = 0; i < elements.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < elements.size(); j++)
        {
            num += elements[(i + j) % elements.size()];
            nums.emplace(num);
        }
    }
    
    return nums.size();
}
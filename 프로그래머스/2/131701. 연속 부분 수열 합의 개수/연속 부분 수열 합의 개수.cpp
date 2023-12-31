#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements)
{
    vector<int> circle(2 * elements.size() - 1);
    for (int i = 0; i < elements.size(); i++)
    {
        circle[i] = elements[i];
        if (i < elements.size() - 1)
            circle[i + elements.size()] = elements[i];
    }
    
    unordered_set<int> nums;
    for (int i = 0; i < elements.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < elements.size(); j++)
        {
            num += circle[i + j];
            nums.emplace(num);
        }
    }
    
    return nums.size();
}
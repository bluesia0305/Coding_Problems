#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    int n = num_list.size();
    num_list.push_back(num_list[n - 1] > num_list[n - 2] ? num_list[n - 1] - num_list[n - 2] : 2 * num_list[n - 1]);
    return num_list;
}
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> array)
{
    map<int, int> map;
    for (int n : array)
        map[n]++;
    
    vector<pair<int, int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(),
         [](const pair<int, int>& p1, const pair<int, int>& p2)
         {
             return p1.second > p2.second;
         });
    
    if (vec[0].second == vec[1].second)
        return -1;
    else
        return vec[0].first;
}
#include <vector>
#include <algorithm>

using namespace std;

void Partition(vector<vector<int>>& partition, const vector<int>& cards, vector<int>& used, int start)
{
    if (used[cards[start] - 1])
        return;
    
    partition.push_back(vector<int>());
    vector<int>& p = partition.back();
    while (!used[cards[start] - 1])
    {
        p.push_back(cards[start]);
        used[cards[start] - 1] = true;
        start = cards[start] - 1;
    }
}

int solution(vector<int> cards)
{
    int n = cards.size();
    vector<int> used(n);
    vector<vector<int>> partition(1);
    
    for (int i = 0; i < n; i++)
        Partition(partition, cards, used, i);
    
    sort(partition.begin(),
         partition.end(),
         [](const vector<int>& a, const vector<int>& b)
         {
             return a.size() > b.size();
         });
    
    return partition[0].size() * partition[1].size();
}
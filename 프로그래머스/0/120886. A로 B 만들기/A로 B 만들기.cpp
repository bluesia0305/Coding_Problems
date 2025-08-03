#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string before, string after)
{
    unordered_map<char, int> umap1;
    unordered_map<char, int> umap2;
    
    for (char c : before)
        umap1[c]++;
    
    for (char c : after)
        umap2[c]++;
    
    for (pair<char, int> p : umap1)
        if (p.second != umap2[p.first])
            return 0;
    
    return 1;
}
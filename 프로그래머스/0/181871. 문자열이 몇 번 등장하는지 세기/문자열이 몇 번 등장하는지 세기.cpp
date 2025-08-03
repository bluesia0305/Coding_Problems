#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string myString, string pat)
{
    unordered_map<string, int> umap;
    for (int i = 0; i < myString.size() - pat.size() + 1; i++)
    {
        umap[myString.substr(i, pat.size())]++;
    }
    
    return umap[pat];
}
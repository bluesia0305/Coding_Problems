#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> um;
    for (const vector<string>& v : clothes)
        um[v[1]]++;
    
    for (const pair<string, int> p : um)
        answer *= p.second + 1;
    
    return answer - 1;
}
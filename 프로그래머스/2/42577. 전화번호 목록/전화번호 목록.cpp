#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book)
{    
    unordered_map<string, int> hashes;
    for (const string& s : phone_book)
        hashes[s]++;
    
    for (const string& s : phone_book)
        for (int i = 0; i < s.size(); i++)
            if (hashes[s.substr(0, i)])
                return false;
    
    return true;
}
#include <string>
#include <vector>

using namespace std;

string Word[5] = { "A", "E", "I", "O", "U" };

vector<string> Dictionary;

void MakeDictionary(string str, string find_word, bool& bFind)
{   
    if (str.size() > 5 || bFind)
        return;
    
    if (str == find_word)
        bFind = true;
    
    if (str.size() > 0)
        Dictionary.push_back(str);
        
    for (int i = 0; i < 5; i++)
        MakeDictionary(str + Word[i], find_word, bFind);
}

int solution(string word)
{
    bool bIsFinded = false;
    MakeDictionary("", word, bIsFinded);    
    return Dictionary.size();
}
#include <string>
#include <vector>

using namespace std;

long long solution(string numbers)
{
    vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 0; i < words.size(); i++)
    {
        auto idx = numbers.find(words[i]);
        while (idx != std::string::npos)
        {
            numbers.replace(idx, words[i].size(), to_string(i));
            idx = numbers.find(words[i]);
        }
    }
    
    return stoll(numbers);
}
#include <string>
#include <vector>

using namespace std;

long long solution(string numbers)
{
    string eng[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string num[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    
    for (int i = 0; i < 10; i++)
    {
        auto idx = numbers.find(eng[i]);
        while (idx != std::string::npos)
        {
            numbers.replace(idx, eng[i].size(), num[i]);
            idx = numbers.find(eng[i]);
        }
    }
    
    return stoll(numbers);
}
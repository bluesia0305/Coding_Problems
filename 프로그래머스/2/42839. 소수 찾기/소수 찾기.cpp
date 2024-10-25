#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

#include <iostream>

using namespace std;

unordered_set<int> Numbers;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    
    for (int i = 2; i <= sqrt(n); i++)
        if (!(n % i))
            return false;
    
    return true;
}

void makeNumbers(string num, string numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        string l = numbers.substr(0, i);
        string c = numbers.substr(i, 1);
        string r = numbers.substr(i + 1);
        
        for (int j = 0; j < num.size(); j++)
        {
            string temp = num;
            temp.replace(j, 1, c + num.substr(j, 1));
            
            Numbers.emplace(stoi(temp));
            makeNumbers(temp, l + r);
        }
        
        Numbers.emplace(stoi(num + c));
        makeNumbers(num + c, l + r);
    }
}

int solution(string numbers)
{
    int answer = 0;
    makeNumbers("", numbers);
    
    for (int n : Numbers)
        if (isPrime(n))
            answer++;
            
    return answer;
}
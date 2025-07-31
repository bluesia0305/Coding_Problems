#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (string s : quiz)
    {
        istringstream ss(s);
        vector<string> terms;
        string buffer;
        
        while (getline(ss, buffer, ' '))
            terms.push_back(buffer);
        
        if (terms[1] == "+")
            answer.push_back(stoi(terms[0]) + stoi(terms[2]) == stoi(terms[4]) ? "O" : "X");
        else if (terms[1] == "-")
            answer.push_back(stoi(terms[0]) - stoi(terms[2]) == stoi(terms[4]) ? "O" : "X");
    }
    
    return answer;
}
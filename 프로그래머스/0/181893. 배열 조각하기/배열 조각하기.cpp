#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query)
{
    vector<int> answer(arr);
    
    for (int i = 0; i < query.size(); i++)
    {
        if (i % 2)
            answer = vector<int>(answer.begin() + query[i], answer.end());
        else
            answer = vector<int>(answer.begin(), answer.begin() + query[i] + 1);
    }

    return answer;
}
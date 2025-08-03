#include <string>
#include <sstream>
#include <stack>

using namespace std;

int solution(string s)
{
    istringstream ss(s);
    string buffer;
    stack<int> st;
    while (getline(ss, buffer, ' '))
    {
        if (buffer == "Z")
            st.pop();
        else
            st.push(stoi(buffer));
    }
    
    int answer = 0;
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    
    return answer;
}
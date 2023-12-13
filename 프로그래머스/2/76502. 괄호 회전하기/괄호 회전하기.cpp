#include <string>
#include <stack>

using namespace std;

stack<char> Stack;

bool decision(string s)
{
	for (char c : s)
	{
		switch (c)
		{
			case '(': case '{': case '[':
			{
				Stack.push(c);
				break;
			}
			
			case ')':
			{
				if (Stack.empty() || Stack.top() != '(') return false;
				Stack.pop();
				break;
			}
			case '}':
			{
				if (Stack.empty() || Stack.top() != '{') return false;
				Stack.pop();
				break;
			}
			case ']':
			{
				if (Stack.empty() || Stack.top() != '[') return false;
				Stack.pop();
				break;
			}
		}
	}

	return Stack.empty();
}

int solution(string s)
{
	int answer = 0;
	int n = s.size();

	s += s;
	for (int i = 0; i < n; i++)
		if (decision(s.substr(i, n)))
			answer++;

	return answer;
}
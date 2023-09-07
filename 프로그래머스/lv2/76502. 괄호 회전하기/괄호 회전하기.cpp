#include <string>

using namespace std;

bool decision(string s)
{
	int len = (int)s.size() + 1;
	while (len != (int)s.size())
	{
		len = s.size();
		if (s.find("()") < s.size())
			s.replace(s.find("()"), 2, "");

		if (s.find("{}") < s.size())
			s.replace(s.find("{}"), 2, "");

		if (s.find("[]") < s.size())
			s.replace(s.find("[]"), 2, "");
	}

	return s.empty();
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
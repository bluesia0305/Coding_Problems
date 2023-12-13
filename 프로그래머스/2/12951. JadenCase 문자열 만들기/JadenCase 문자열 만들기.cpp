#include <string>

using namespace std;

string solution(string s)
{
	string answer;
	while ((int)s.size() > 0)
	{
		while (s[0] == ' ')
		{
			answer += " ";
			s = s.substr(1);
		}

		int end = (int)s.find_first_of(' ');
		string word = s.substr(0, end);
		for (int i = 0; i < word.size(); i++)
			word[i] = i ? tolower(word[i]) : toupper(word[i]);

		answer += word;

		if (end == string::npos)
			break;

		s = s.substr(end);
	}

	return answer;
}
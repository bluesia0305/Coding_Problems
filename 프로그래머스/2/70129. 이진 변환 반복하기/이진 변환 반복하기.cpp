#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
	vector<int> answer(2);
	while (true)
	{
		if (s == "1")
			break;

		string temp;
		for (char c : s)
			if (c == '1')
				temp += "1";
			else
				answer[1]++;

		int n = temp.size();
		int z = 0x01;
		temp = "";
		while (n >= z)
		{
			temp = (n & z ? "1" : "0") + temp;
			z <<= 1;
		}
		
		s = temp;
		answer[0]++;
	}

	return answer;
}
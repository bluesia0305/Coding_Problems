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

		string str;
		for (char c : s)
			if (c == '1')
				str += "1";
			else
				answer[1]++;

		int n = str.size();
		int z = 0x01;
		string binary;
		while (n >= z)
		{
			binary = (n & z ? "1" : "0") + binary;
			z <<= 1;
		}
		
		s = binary;
		answer[0]++;
	}

	return answer;
}
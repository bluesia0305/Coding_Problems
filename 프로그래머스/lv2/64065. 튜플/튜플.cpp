#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
	unordered_map<string, int> Numbers;
	string elem;
	for (char c : s)
	{
		if (0 <= c - '0' && c - '0' <= 9)
			elem.push_back(c);

		if (c == ',' || c == '}')
		{
			if (elem == "")
				continue;
			
			Numbers[elem]++;
			elem = "";
		}
	}

	std::vector<std::pair<std::string, int>> sorted(Numbers.begin(), Numbers.end());
	sort(sorted.begin(), sorted.end(),
		 [](const pair<string, int>& a, const pair<string, int>& b)
		 {
			 return a.second > b.second;
		 });

	vector<int> answer;
	for (const pair<string, int>& pair : sorted)
		answer.push_back(stoi(pair.first));
	
	return answer;
}
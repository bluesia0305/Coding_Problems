#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> wordMap;

bool decision(string prev, string next)
{
	return prev.back() == next.front() && wordMap[next] == 1;
}

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer(2);
	wordMap[words[0]]++;

	for (int i = 1; i < words.size(); i++)
	{
		wordMap[words[i]]++;
		if (!decision(words[i - 1], words[i]))
		{
			answer = { i % n + 1, i / n + 1};
			break;
		}
	}

	return answer;
}
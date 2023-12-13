#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Cache;

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;
	for (string city : cities)
	{
		for (char& c : city)
			c = tolower(c);

		auto iter = find(Cache.begin(), Cache.end(), city);
		if (iter != Cache.end())
		{
			Cache.erase(iter);
			Cache.push_back(city);
			answer++;
		}
		else
		{
			if (cacheSize && Cache.size() == cacheSize)
				Cache.erase(Cache.begin());

			if (cacheSize)
				Cache.push_back(city);

			answer += 5;
		}
	}

	return answer;
}
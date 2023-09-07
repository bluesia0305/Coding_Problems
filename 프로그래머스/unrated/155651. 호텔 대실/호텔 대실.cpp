#include <string>
#include <vector>

using namespace std;

int Times[1440];

int convert(const string& str)
{
	int hour = (str[0] - '0') * 10 + (str[1] - '0');
	int min = (str[3] - '0') * 10 + (str[4] - '0');

	return 60 * hour + min;
}

int solution(vector<vector<string>> book_time)
{
	int answer = 0;
	for (vector<string> time : book_time)
	{
		for (int i = convert(time[0]); i < convert(time[1]) + 10; i++)
		{
			if (i >= 1440)
				break;

			Times[i]++;
			if (answer < Times[i])
				answer = Times[i];
		}
	}

	return answer;
}
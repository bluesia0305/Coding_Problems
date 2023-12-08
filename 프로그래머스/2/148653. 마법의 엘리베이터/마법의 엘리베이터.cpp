#include <string>
#include <vector>

using namespace std;

int solution(int storey)
{
	int answer = 0;
	string s = to_string(storey);

	vector<int> digits(9);
	for (int i = 0; i < s.size(); i++)
		digits[i] = s[s.size() - 1 - i] - '0';

	for (int i = 0; i < 8; i++)
	{
		if (digits[i] < 5)
			answer += digits[i];
		else if (digits[i] > 5)
		{
			answer += 10 - digits[i];
			digits[i + 1]++;
		}
		else
		{
			answer += 5;
			if (digits[i + 1] >= 5)
				digits[i + 1]++;
		}
	}

	answer += digits[8];
	return answer;
}
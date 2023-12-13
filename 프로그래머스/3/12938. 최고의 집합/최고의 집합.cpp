#include <vector>

using namespace std;

void Decompose(vector<int>& num_list, int n, int s)
{
	if (n > 0 && s / n <= 0)
	{
		num_list.clear();
		num_list.push_back(-1);
		return;
	}
	
	num_list.push_back(s / n);

	if (n > 1)
		Decompose(num_list, n - 1, s - s / n);
}

vector<int> solution(int n, int s)
{
	vector<int> answer;
	Decompose(answer, n, s);

	return answer;
}
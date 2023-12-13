#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
	int n = citations.size();
	sort(citations.begin(),
		 citations.end(),
		 [](const int& A, const int& B) { return A > B; });

	int left = 0, right = n;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (citations[middle] > middle)
			left = middle + 1;
		else
			right = middle;
	}

	return right;
}
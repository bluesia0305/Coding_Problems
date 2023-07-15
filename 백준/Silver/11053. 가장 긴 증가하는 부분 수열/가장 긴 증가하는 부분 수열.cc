#include <iostream>
#include <vector>

using namespace std;

struct IS
{
	int LastNum;
	int Length;
};

vector<IS> ISs;

void Try_Append(int num)
{
	int left = 0, right = ISs.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (num < ISs[middle].LastNum)
			right = middle - 1;
		else
			left = middle + 1;
	}

	if (ISs[right].LastNum < num)
	{
		if (ISs.size() <= left)
			ISs.push_back(IS{ num, ISs.back().Length + 1 });
		else
			if (ISs[left].LastNum > num)
				ISs[left].LastNum = num;
	}
}

int main()
{
	int N;
	cin >> N;

	ISs.push_back(IS{ 0, 0 });
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		Try_Append(num);
	}

	cout << ISs.back().Length << "\n";
	return 0;
}
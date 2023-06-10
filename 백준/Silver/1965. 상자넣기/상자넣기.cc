#include <iostream>
#include <vector>

using namespace std;

struct IS
{
	int Box;
	int Count;
};

vector<IS> ISs;

void Append(int num)
{
	int left = 0, right = ISs.size() - 1;
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (num < ISs[middle].Box)
			right = middle - 1;
		else
			left = middle + 1;
	}

	if (ISs[left - 1].Box < num)
	{
		if (ISs.size() > left)
		{
			if (ISs[left].Box > num)
				ISs[left].Box = num;
		}
		else
			ISs.push_back(IS{ num, ISs.back().Count + 1 });
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
		Append(num);
	}

	cout << ISs.back().Count << "\n";
	return 0;
}
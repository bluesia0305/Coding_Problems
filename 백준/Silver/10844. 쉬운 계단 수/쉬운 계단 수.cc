#include <iostream>

using namespace std;

int Count[10];
int Intermediate[10];

int main()
{
	int N;
	cin >> N;

	N--;
	for (int i = 1; i < 10; i++)
		Count[i] = 1;

	while (N--)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
				Intermediate[i] = Count[1];
			else if (i == 9)
				Intermediate[i] = Count[8];
			else
				Intermediate[i] = (Count[i - 1] + Count[i + 1]) % 1000000000;
		}

		for (int i = 0; i < 10; i++)
			Count[i] = Intermediate[i];
	}

	int TotalCount = 0;
	for (int n : Count)
	{
		TotalCount += n;
		TotalCount %= 1000000000;
	}

	cout << TotalCount << "\n";
	return 0;
}
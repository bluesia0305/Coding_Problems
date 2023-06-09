#include <iostream>

using namespace std;

int Stairs[300];
int Scores[300];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Stairs[i];

		if (i > 2)
		{
			int score = Stairs[i - 1] + Scores[i - 3];
			Scores[i] = Stairs[i] + (Scores[i - 2] > score ? Scores[i - 2] : score);
		}
		else
		{
			switch (i)
			{
			case 0:
				Scores[i] = Stairs[i];
				break;

			case 1:
				Scores[i] = Stairs[i] + Stairs[i - 1];
				break;

			case 2:
				Scores[i] = Stairs[i] + (Stairs[i - 1] > Stairs[i - 2] ? Stairs[i - 1] : Stairs[i - 2]);
				break;
			}
		}
	}
	cout << Scores[N - 1] << "\n";
	return 0;
}
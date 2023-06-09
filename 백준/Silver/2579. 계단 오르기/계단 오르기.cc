#include <iostream>

using namespace std;

int Stairs[301];
int Scores[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> Stairs[i];

		if (i > 2)
		{
			int score = Stairs[i - 1] + Scores[i - 3];
			Scores[i] = Stairs[i] + (Scores[i - 2] > score ? Scores[i - 2] : score);
		}
		else if (i == 1)
			Scores[i] = Stairs[i];
		else if (i == 2)
			Scores[i] = Stairs[i] + Stairs[i - 1];
	}
	cout << Scores[N] << "\n";
	return 0;
}
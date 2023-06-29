#include <iostream>
#include <vector>

using namespace std;

int N;
int S[20][20];
int Min = 2147483647;

int TeamScore(vector<int>& team)
{
	int sum = 0;
	for (int i : team)
		for (int j : team)
			sum += S[i][j];

	return sum;
}

void Select(vector<int>& team, int n)
{
	if (n < N || !Min)
	{
		team.push_back(n);

		if ((int)team.size() == N / 2)
		{
			vector<int> team2;
			int idx = 0;
			for (int i = 0; i < N; i++)
			{
				if (team[idx] == i)
				{
					if (idx < N / 2 - 1)
						idx++;
					continue;
				}
			
				team2.push_back(i);
			}
			
			int diff = abs(TeamScore(team) - TeamScore(team2));
			if (Min > diff)
				Min = diff;

			return;
		}

		for (int i = n + 1; i < N; i++)
		{
			Select(team, i);
			team.pop_back();
		}
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}

	for (int i = 0; i < N / 2 + 1; i++)
	{
		vector<int> Team;
		Select(Team, i);
	}

	cout << Min << "\n";
	return 0;
}
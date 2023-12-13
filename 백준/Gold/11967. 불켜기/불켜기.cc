#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define Coord pair<int, int>
#define X first
#define Y second

int Map[102][102];		// 0: Switch Off, 1: Switch On, 2: Connected to (1, 1)
map<Coord, vector<Coord>> Switches;

int dx[4] = { -1, 1,  0, 0 };
int dy[4] = {  0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	while (M--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		Switches[Coord{ x, y }].push_back(Coord{ a, b });
	}

	queue<Coord> q;
	q.push(Coord{ 1, 1 });
	Map[1][1] = 2;
	int lights = 1;
	while (!q.empty())
	{
		Coord curr = q.front();
		q.pop();

		for (Coord c : Switches[curr])
			if (!Map[c.X][c.Y])
			{
				Map[c.X][c.Y] = 1;
				lights++;
				for (int i = 0; i < 4; i++)		// whenever switch turn on, find adjacent visited room
				{
					int x = c.X + dx[i];
					int y = c.Y + dy[i];
					if (Map[x][y] == 2)
					{
						Map[c.X][c.Y] = 2;
						q.push(c);
						break;
					}
				}
			}

		for (int i = 0; i < 4; i++)
		{
			int x = curr.X + dx[i];
			int y = curr.Y + dy[i];
			if (Map[x][y] == 1)
			{
				Map[x][y] = 2;
				q.push(Coord{ x, y });
			}
		}
	}

	cout << lights << "\n";
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int TestTube[200][200];
int N, K, S, X, Y;

struct Coord
{
	int Row;
	int Col;

	bool operator>(const Coord& Other) const
	{ return TestTube[Row][Col] > TestTube[Other.Row][Other.Col]; }
};

priority_queue<Coord, vector<Coord>, greater<>> PQ;

void Initiate()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (TestTube[i][j])
				PQ.emplace(Coord{ i, j });
}

void Contaminate(priority_queue<Coord, vector<Coord>, greater<>>& pq, int row, int col, int dRow, int dCol)
{
	int x = row + dRow, y = col + dCol;
	if (x >= 0 && x < N &&
		y >= 0 && y < N &&
		!TestTube[x][y])
	{
		TestTube[x][y] = TestTube[row][col];
		pq.emplace(Coord{ x, y });
	}
}

void Propagate()
{
	if (TestTube[X - 1][Y - 1])
		return;

	priority_queue<Coord, vector<Coord>, greater<>> pq;
	while (!PQ.empty())
	{
		Coord coord = PQ.top();
		PQ.pop();

		if (TestTube[coord.Row][coord.Col])
		{
			Contaminate(pq, coord.Row, coord.Col, 1, 0);
			Contaminate(pq, coord.Row, coord.Col, 0, 1);
			Contaminate(pq, coord.Row, coord.Col, -1, 0);
			Contaminate(pq, coord.Row, coord.Col, 0, -1);
		}
	}

	if (pq.empty())
		return;

	PQ.swap(pq);
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> TestTube[i][j];

	cin >> S >> X >> Y;

	Initiate();

	for (int i = 0; i < S; i++)
		Propagate();

	cout << TestTube[X - 1][Y - 1] << "\n";
	return 0;
}
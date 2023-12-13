#include <iostream>
#include <vector>
#include <queue>
#define MAX 102
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
bool map[MAX][MAX], visit[MAX][MAX];
vector<pair<int, int>> sw[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		sw[x][y].push_back({ a, b });
	}

	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	map[1][1] = visit[1][1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (auto& p : sw[x][y]) {
			if (map[p.first][p.second]) continue;
			map[p.first][p.second] = true;
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (visit[nx][ny]) q.push({ nx, ny });
			}
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[nx][ny] || !map[nx][ny]) continue;
			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}
	cout << cnt;
}
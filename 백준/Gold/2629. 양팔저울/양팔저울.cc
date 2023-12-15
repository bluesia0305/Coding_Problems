#include <bits/stdc++.h>
using namespace std;

int n, chu[31], m, chu_max;
bool dy[40001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> chu[i];
		chu_max += chu[i];
	}
	
	dy[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = chu_max; j >= 0; j--)
			if (dy[j]) dy[j + chu[i]] = 1;
		for (int j = 0; j <= chu_max; j++)
			if (dy[j]) dy[abs(j - chu[i])] = 1;
	}


	//for (int j = 0; j <= chu_max; j++) {
	//	cout << dy[j] << " ";
	//}
	//cout << '\n';


	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (dy[tmp]) cout << "Y ";
		else cout << "N ";
	}
}
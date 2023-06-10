#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
	int X;
	int Y;
};

Point Points[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Points[i].X >> Points[i].Y;

	sort(&Points[0], &Points[N - 1] + 1, 
		 [](Point a, Point b)
		 {
			if (a.X == b.X)
				return a.Y < b.Y;

			return a.X < b.X;
		 });

	for (int i = 0; i < N; i++)
		cout << Points[i].X << " " << Points[i].Y << "\n";

	return 0;
}
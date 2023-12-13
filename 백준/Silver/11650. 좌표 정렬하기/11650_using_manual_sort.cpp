#include <iostream>

using namespace std;

struct Point
{
	int X;
	int Y;
};

Point Points[100000];
Point Sorted[100000];

void Merge(int start, int middle, int end, bool (*_Pr)(const Point&, const Point&))
{
	int left = start;
	int right = middle + 1;

	int index = left;
	while (left <= middle && right <= end)
	{
		if (_Pr(Points[left], Points[right]))
			Sorted[index++] = Points[left++];
		else
			Sorted[index++] = Points[right++];
	}

	while (left <= middle)
		Sorted[index++] = Points[left++];

	while (right <= end)
		Sorted[index++] = Points[right++];

	for (int i = start; i <= end; i++)
		Points[i] = Sorted[i];
}

void MergeSort(int start, int end, bool (*_Pr)(const Point&, const Point&))
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		MergeSort(start, middle, _Pr);
		MergeSort(middle + 1, end, _Pr);
		Merge(start, middle, end, _Pr);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Points[i].X >> Points[i].Y;

	MergeSort(0, N - 1,
			  [](const Point& a, const Point& b)
			  {
				  if (a.X == b.X)
					  return a.Y < b.Y;

				  return a.X < b.X;
			  });

	for (int i = 0; i < N; i++)
		cout << Points[i].X << " " << Points[i].Y << "\n";

	return 0;
}
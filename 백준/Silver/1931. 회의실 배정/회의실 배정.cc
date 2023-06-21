#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Meeting
{
	int Start;
	int End;
};

vector<Meeting> Meetings;

int main()
{
	int N;
	cin >> N;

	vector<Meeting> Meetings(N);
	for (int i = 0; i < N; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		Meetings[i] = Meeting{ t1, t2 };
	}

	sort(Meetings.begin(), Meetings.end(),
		 [](const Meeting& a, const Meeting& b)
		 {
			 if (a.End == b.End)
				 return a.Start < b.Start;

			 return a.End < b.End;
		 });

	int Start = 0, Count = 0;
	for (Meeting meeting : Meetings)
		if (meeting.Start >= Start)
		{
			Count++;
			Start = meeting.End;
		}

	cout << Count << "\n";
	return 0;
}
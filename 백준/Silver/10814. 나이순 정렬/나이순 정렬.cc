#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Member
{
	string Name;
	int Age;
	int Index;
};

Member Members[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		Members[i].Index = i;
		cin >> Members[i].Age >> Members[i].Name;
	}

	sort(&Members[0], &Members[N - 1] + 1,
		 [](const Member& A, const Member& B)
		 {
			 if (A.Age == B.Age)
				 return A.Index < B.Index;

			 return A.Age < B.Age;
		 });

	for (int i = 0; i < N; i++)
		cout << Members[i].Age << " " << Members[i].Name << "\n";

	return 0;
}
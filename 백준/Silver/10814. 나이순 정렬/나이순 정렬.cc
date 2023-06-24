#include <iostream>
#include <algorithm>

using namespace std;

struct Member
{
	char Name[101];
	unsigned char Age;
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
		int age;
		Members[i].Index = i;
		cin >> age >> Members[i].Name;
		Members[i].Age = (unsigned char)age;
	}

	sort(&Members[0], &Members[N - 1] + 1,
		 [](const Member& A, const Member& B)
		 {
			 if (A.Age == B.Age)
				 return A.Index < B.Index;

			 return A.Age < B.Age;
		 });

	for (int i = 0; i < N; i++)
		cout << (int)Members[i].Age << " " << Members[i].Name << "\n";

	return 0;
}
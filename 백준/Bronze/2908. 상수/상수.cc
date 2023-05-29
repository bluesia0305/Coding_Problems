#include <iostream>

using namespace std;

int main()
{
	char A[4] = { 0, };
	char B[4] = { 0, };
	bool PrintB = true;
	cin >> A >> B;

	for (int i = 2; i >= 0; i--)
	{
		if (A[i] == B[i])
			continue;

		if (A[i] > B[i])
			PrintB = false;
		
		break;
	}

	for (int i = 0; i < 3; i++)
		cout << (PrintB ? B[2 - i] : A[2 - i]);
	cout << "\n";

	return 0;
}
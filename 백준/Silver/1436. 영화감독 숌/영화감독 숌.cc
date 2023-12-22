#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, Ans = 665;
	cin >> N;

	for (int cnt = 1; cnt <= N; cnt++)
	{
		while (true)
		{
			Ans++;

			if (to_string(Ans).find("666", 0, 3) != string::npos)
				break;
		}
	}

	cout << Ans << "\n";
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int n = 0;
	int cnt = 0;
	while (true)
	{
		int left = n;
		int sixes = 0;
		int tens = 1;
		while (true)
		{
			if (left % 10 == 6)
			{
				sixes++;
				tens *= 10;
				left /= 10;
			}
			else
				break;
		}

		if (sixes)
		{
			for (int i = 0; i < tens; i++)
			{
				string right = to_string(i);
				while (right.size() < sixes)
					right = "0" + right;

				if (++cnt == N)
				{
					cout << stoi(to_string(left) + "666" + right) << "\n";
					return 0;
				}
			}
		}
		else
		{
			if (++cnt == N)
			{
				cout << stoi(to_string(n) + "666") << "\n";
				return 0;
			}
		}
        
		n++;
	}
}
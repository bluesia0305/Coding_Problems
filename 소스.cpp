#include <iostream>
#include <string>

using namespace std;

int test(int N)
{
	int Ans = 665;
	for (int cnt = 1; cnt <= N; cnt++)
	{
		while (true)
		{
			Ans++;

			if (to_string(Ans).find("666", 0, 3) != string::npos)
				break;
		}
	}

	return Ans;
}

int test2(int N)
{
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
					return stoi(to_string(left) + "666" + right);
			}
		}
		else
		{
			if (++cnt == N)
				return stoi(to_string(n) + "666");
		}
		n++;
	}
}

int main()
{
	// 23934 , 24000
	int left = 23934;
	int right = 24000;
	while (left < right)
	{
		int i = (left + right) / 2;
		int a = test(i);
		int b = test2(i);
		if (a != b)
		{
			cout << i << "\n";
			cout << "정답: " << a << "\n";
			cout << "오답: " << b << "\n";
			right = i;
		}
		else
		{
			cout << i << "\n";
			cout << "답이 같음: " << a << ", " << b << "\n";
			left = i + 1;
		}
	}
}
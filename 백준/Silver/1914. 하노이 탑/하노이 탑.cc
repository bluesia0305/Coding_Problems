// 1914번: 하노이의 탑 (https://www.acmicpc.net/problem/1914)
// 참고사항)
// 자료형의 표현범위를 넘어서는 임의의 큰 수에 대한 계산

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MultiplyTwo(string& largeNum)
{
	vector<char> result;
	result.push_back(0);

	for (char str : largeNum)
		result.push_back((str - '0') * 2);

	for (size_t i = result.size() - 1; i > 1; --i)
	{
		if (result[i])
		{
			result[i - 1] += (int)result[i] / 10;
			result[i] = (int)result[i] % 10;
		}
	}

	while (!result[0])
		result.erase(result.begin());

	largeNum = "";
	for (char c : result)
		largeNum += to_string(c);
}

void SubtractOne(string& largeNum)
{
	int digit = largeNum.length();
	largeNum.back() -= 1;
	for (int i = 0; i < digit; i++)
	{
		if (largeNum[digit - 1 - i] < '0')
		{
			largeNum[digit - 1 - i] += 10;
			largeNum[digit - 2 - i] -= 1;
		}
		else
			break;
	}
}

void HanoiCount(string& count, int N)
{
	for (int i = 0; i < N; i++)
		MultiplyTwo(count);
	SubtractOne(count);
	cout << count << "\n";
}

void Hanoi(int N, int from, int dest, int temp)
{
	if (N > 1)
		Hanoi(N - 1, from, temp, dest);

	cout << from << " " << dest << "\n";

	if (N > 1)
		Hanoi(N - 1, temp, dest, from);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	string Count = "1";
	HanoiCount(Count, N);

	if (N <= 20)
		Hanoi(N, 1, 3, 2);

	return 0;
}
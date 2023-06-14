#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";

	int i = 1;
	while (true)
	{
		int num = q.front();
		q.pop();

		if (i++ % K)
			q.push(num);
		else
		{
			cout << num;
			if (q.empty())
				break;

			cout << ", ";
		}
	}

	cout << ">";
	return 0;
}
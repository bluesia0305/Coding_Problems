#include <iostream>

using namespace std;

int Deque[19998];
int Front = 10000;
int Rear = Front - 1;
int Size;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	while (N--)
	{
		string Op;
		cin >> Op;

		if (Op == "push_front")
		{
			cin >> Deque[--Front];
			Size++;
		}
		else if (Op == "push_back")
		{
			cin >> Deque[++Rear];
			Size++;
		}

		else if (Op == "pop_front")
		{
			if (Rear < Front)
				cout << "-1\n";
			else
			{
				cout << Deque[Front++] << "\n";
				Size--;
			}
		}
		else if (Op == "pop_back")
		{
			if (Rear < Front)
				cout << "-1\n";
			else
			{
				cout << Deque[Rear--] << "\n";
				Size--;
			}
		}

		else if (Op == "size")
			cout << Size << "\n";
		else if (Op == "empty")
			cout << (Rear < Front) << "\n";

		else if (Op == "front")
		{
			if (Rear < Front)
				cout << "-1\n";
			else
				cout << Deque[Front] << "\n";
		}
		else if (Op == "back")
		{
			if (Rear < Front)
				cout << "-1\n";
			else
				cout << Deque[Rear] << "\n";
		}
	}

	return 0;
}
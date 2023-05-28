#include <iostream>
#include <vector>

using namespace std;

class queue
{
public:
	void push(int num)
	{
		Queue.push_back(num);
		Rear++;
		Count++;
	}

	void pop()
	{
		front();
		if (Count)
		{
			Front++;
			Count--;
		}
	}

	void size() { cout << Count << "\n"; }
	void empty() { cout << (Count ? 0 : 1) << "\n"; }

	void front()
	{
		if (!Count)
			cout << "-1\n";
		else
			cout << Queue.at(Front) << "\n";
	}

	void back()
	{
		if (!Count)
			cout << "-1\n";
		else
			cout << Queue.at(Rear) << "\n";
	}

private:
	vector<int> Queue;
	int Front = 0;
	int Rear = -1;
	size_t Count = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	int num;
	string str;
	cin >> N;

	queue q;
	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (str == "front")	{ q.front(); }
		else if (str == "back")		{ q.back(); }
		else if (str == "size")		{ q.size(); }
		else if (str == "empty")	{ q.empty(); }
		else if (str == "pop")		{ q.pop(); }
	}

	return 0;
}
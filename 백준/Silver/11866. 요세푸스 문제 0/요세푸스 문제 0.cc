#include <iostream>

using namespace std;

class CQueue
{
public:
	CQueue(int N)
	{
		Numbers = new int[N + 1];
		Capacity = Rear = N;
		for (int i = 0; i < N + 1; i++)
			Numbers[i] = i;
	}

	~CQueue()
	{
		delete[] Numbers;
	}

	void Enqueue(int n)
	{
		if (IsFull())
			return;

		Rear = ++Rear % (Capacity + 1);
		Numbers[Rear] = n;
	}

	int Dequeue()
	{
		if (IsEmpty())
			return -1;

		Front = ++Front % (Capacity + 1);
		int temp = Numbers[Front];
		Numbers[Front] = 0;
		return temp;
	}

	bool IsFull() const
	{
		return Front == (Rear + 1) % (Capacity + 1);
	}

	bool IsEmpty() const
	{
		return Front == Rear;
	}

private:
	int* Numbers;
	int Capacity;
	int Front = 0;
	int Rear = 1;
};

int main()
{
	int N, K;
	cin >> N >> K;

	CQueue cq = CQueue(N);

	cout << "<";

	int i = 1;
	while (true)
	{
		int num = cq.Dequeue();
		if (i++ % K)
			cq.Enqueue(num);
		else
		{
			cout << num;
			if (cq.IsEmpty())
				break;

			cout << ", ";
		}
	}

	cout << ">";
	return 0;
}
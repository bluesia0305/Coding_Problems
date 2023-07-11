#include <iostream>

using namespace std;

class MinHeap
{
public:
	void Swap(int idx1, int idx2)
	{
		int temp = Data[idx1];
		Data[idx1] = Data[idx2];
		Data[idx2] = temp;
	}

	void Add(int n)
	{
		int current = Count;
		Data[Count++] = n;

		while (current > 0)
		{
			int parent = current % 2 ? (current - 1) / 2 : current / 2 - 1;
			if (Data[parent] <= n)
				break;

			Swap(parent, current);
			current = parent;
		}
	}

	void Extract()
	{
		if (!Count)
		{
			cout << "0\n";
			return;
		}

		cout << Data[0] << "\n";
		Count--;

		Swap(0, Count);
		int current = 0;

		while (current < Count)
		{
			int leftChild = 2 * current + 1;
			if (leftChild >= Count)
				return;

			if (leftChild < Count)
			{
				int minChild = leftChild;
				if (leftChild + 1 < Count)
					minChild = Data[leftChild] < Data[leftChild + 1] ? leftChild : leftChild + 1;

				if (Data[current] <= Data[minChild])
					return;
				
				Swap(minChild, current);
				current = minChild;
			}
		}
	}

private:
	int Data[100000];
	int Count;
};

int N;
MinHeap Heap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;

		if (num)
			Heap.Add(num);
		else
			Heap.Extract();
	}

	return 0;
}
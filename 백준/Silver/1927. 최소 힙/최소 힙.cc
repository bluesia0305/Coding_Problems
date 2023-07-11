#include <iostream>

using namespace std;

class MinHeap
{
public:
	void Insert(int n)
	{
		int current = Count;
		Data[Count++] = n;

		while (current > 0)
		{
			int parent = (current - 2 + current % 2) / 2;
			if (Data[parent] <= n)
				break;

			Swap(parent, current);
			current = parent;
		}
	}

	int Extract()
	{
		if (!Count)
			return 0;

		int retVal = Data[0];
		Count--;
		Swap(0, Count);

		int current = 0;
		while (current < Count)
		{
			int leftChild = 2 * current + 1;
			if (leftChild >= Count)
				break;

			if (leftChild < Count)
			{
				int minChild = leftChild;
				if (leftChild + 1 < Count)
					if (Data[leftChild] > Data[leftChild + 1])
						minChild++;

				if (Data[current] <= Data[minChild])
					break;
				
				Swap(minChild, current);
				current = minChild;
			}
		}

		return retVal;
	}

private:
	void Swap(int idx1, int idx2)
	{
		int temp = Data[idx1];
		Data[idx1] = Data[idx2];
		Data[idx2] = temp;
	}

private:
	int Data[100000] = { 0, };
	int Count = 0;
};

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	MinHeap heap;
	while (N--)
	{
		int num;
		cin >> num;

		if (num)
			heap.Insert(num);
		else
			cout << heap.Extract() << "\n";
	}

	return 0;
}
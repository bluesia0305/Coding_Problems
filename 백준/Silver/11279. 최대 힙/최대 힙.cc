#include <iostream>

using namespace std;

class MaxHeap
{
public:
	void Insert(int num)
	{
		int child = Count;
		Data[Count++] = num;

		while (child > 0)
		{
			int parent = (child - 2 + child % 2) / 2;

			if (Data[parent] < num)
				Swap(parent, child);
			else
				break;

			child = parent;
		}
	}

	int ExtractMax()
	{
		if (!Count)
			return 0;

		const int retVal = Data[0];
		Swap(0, Count - 1);
		Count--;

		int parent = 0;
		while (true)
		{
			int leftChild = 2 * parent + 1;
			int maxChild;

			if (leftChild + 1 > Count)
				break;
			
			if (leftChild + 1 < Count)
				maxChild = Data[leftChild] > Data[leftChild + 1] ? leftChild : leftChild + 1;
			else
				maxChild = leftChild;

			if (Data[parent] < Data[maxChild])
			{
				Swap(parent, maxChild);
				parent = maxChild;
			}
			else
				break;
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
	int Data[100000];
	int Count = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	MaxHeap heap;
	while (N--)
	{
		int num;
		cin >> num;

		if (num)
			heap.Insert(num);
		else
			cout << heap.ExtractMax() << "\n";
	}

	return 0;
}
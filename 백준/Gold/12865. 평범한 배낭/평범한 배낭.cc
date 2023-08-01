#include <iostream>
#include <algorithm>

using namespace std;

struct Item
{
	int W;
	int V;
};

Item Items[100];
int DP[100001];

void Print(int K)
{
	for (int i = 0; i <= K; i++)
		cout << DP[i] << " ";
	cout << "\n";
}

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Items[i].W >> Items[i].V;


	for (int i = 0; i < N; i++)
		for (int k = K; k >= Items[i].W; k--)
			if (k == Items[i].W || DP[k - Items[i].W] > 0)
			{
				int valueSum = DP[k - Items[i].W] + Items[i].V;
				if (DP[k] < valueSum)
					DP[k] = valueSum;
			}

	cout << *max_element(DP, DP + K + 1) << "\n";
	return 0;
}
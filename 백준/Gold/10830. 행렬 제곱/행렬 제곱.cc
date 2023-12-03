#include <iostream>
#include <stack>

using namespace std;

int Matrix[5][5];
int Answer[5][5];

void Multiply(int size, int inMatrix1[5][5], int inMatrix2[5][5], int outMatrix[5][5])
{
	int temp[5][5] = { 0, };
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				temp[i][j] += inMatrix1[i][k] * inMatrix2[k][j];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			outMatrix[i][j] = temp[i][j] % 1000;
}

void Power(int size, unsigned long long exp)
{
	stack<int> operation;
	while (exp > 0)
	{
		if (exp % 2)
		{
			operation.push(1);
			exp -= 1;
		}
		else
		{
			operation.push(2);
			exp /= 2;
		}
	}

	while (!operation.empty())
	{
		int op = operation.top();
		operation.pop();

		if (op == 1)
			Multiply(size, Answer, Matrix, Answer);
		else
			Multiply(size, Answer, Answer, Answer);
	}
}

int main()
{
	int N;
	unsigned long long B;
	cin >> N >> B;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Matrix[i][j];
	
	for (int i = 0; i < N; i++)
		Answer[i][i] = 1;
	
	Power(N, B);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Answer[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
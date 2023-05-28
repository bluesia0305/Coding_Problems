#include <iostream>

using namespace std;

int N;
int Numbers[11];
int Operators[4];
int Max = -1000000000;
int Min = 1000000000;

enum class OPERATION
{
	Add,
	Subtract,
	Multiplication,
	Division
};

void Operation(OPERATION operation, int numOp, int result)
{
	if (Operators[(int)operation] <= 0)
		return;

	int temp = result;
	Operators[(int)operation]--;

	switch (operation)
	{
		case OPERATION::Add:
			result += Numbers[numOp];
			break;
		case OPERATION::Subtract:
			result -= Numbers[numOp];
			break;
		case OPERATION::Multiplication:
			result *= Numbers[numOp];
			break;
		case OPERATION::Division:
			result /= Numbers[numOp];
			break;
	}

	if (numOp == N - 1)
	{
		Max = result > Max ? result : Max;
		Min = result < Min ? result : Min;
	}
	else
	{
		Operation(OPERATION::Add, numOp + 1, result);
		Operation(OPERATION::Subtract, numOp + 1, result);
		Operation(OPERATION::Multiplication, numOp + 1, result);
		Operation(OPERATION::Division, numOp + 1, result);
	}

	Operators[(int)operation]++;
	return;
}

void FindMinMax()
{
	Operation(OPERATION::Add, 1, Numbers[0]);
	Operation(OPERATION::Subtract, 1, Numbers[0]);
	Operation(OPERATION::Multiplication, 1, Numbers[0]);
	Operation(OPERATION::Division, 1, Numbers[0]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> Operators[i];

	FindMinMax();
	cout << Max << "\n" << Min << "\n";

	return 0;
}
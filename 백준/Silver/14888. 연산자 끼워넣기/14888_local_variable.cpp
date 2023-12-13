#include <iostream>
#include <vector>

using namespace std;

enum class OPERATION
{
	Add,
	Subtract,
	Multiplication,
	Division
};

void Operation(const vector<int>& numbers, int operators[4], OPERATION operation, int numOp, int result, int& Min, int& Max)
{
	if (operators[(int)operation] <= 0)
		return;

	int temp = result;
	operators[(int)operation]--;

	switch (operation)
	{
		case OPERATION::Add:
			result += numbers[numOp];
			break;
		case OPERATION::Subtract:
			result -= numbers[numOp];
			break;
		case OPERATION::Multiplication:
			result *= numbers[numOp];
			break;
		case OPERATION::Division:
			result /= numbers[numOp];
			break;
	}

	if (numOp == (int)numbers.size() - 1)
	{
		Max = result > Max ? result : Max;
		Min = result < Min ? result : Min;
	}
	else
	{
		Operation(numbers, operators, OPERATION::Add, numOp + 1, result, Min, Max);
		Operation(numbers, operators, OPERATION::Subtract, numOp + 1, result, Min, Max);
		Operation(numbers, operators, OPERATION::Multiplication, numOp + 1, result, Min, Max);
		Operation(numbers, operators, OPERATION::Division, numOp + 1, result, Min, Max);
	}

	operators[(int)operation]++;
	return;
}

void FindMinMax(const vector<int>& numbers, int operators[4], int& Min, int& Max)
{
	Operation(numbers, operators, OPERATION::Add, 1, numbers[0], Min, Max);
	Operation(numbers, operators, OPERATION::Subtract, 1, numbers[0], Min, Max);
	Operation(numbers, operators, OPERATION::Multiplication, 1, numbers[0], Min, Max);
	Operation(numbers, operators, OPERATION::Division, 1, numbers[0], Min, Max);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> Numbers(N);
	int Operators[4] = { 0, };
	for (int i = 0; i < N; i++)
		cin >> Numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> Operators[i];

	int Max = -1000000000;
	int Min = 1000000000;
	FindMinMax(Numbers, Operators, Min, Max);
	cout << Max << "\n" << Min << "\n";

	return 0;
}
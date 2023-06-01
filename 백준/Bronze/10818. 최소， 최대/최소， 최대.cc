#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int num, Min = 1000000, Max = -1000000;
	cin >> num;

	N--;
	num < Min ? Min = num : 0;
	num > Max ? Max = num : 0;
	
	while (N--)
	{
		cin >> num;
		num < Min ? Min = num : (num > Max ? Max = num : 0);
	}
    
	cout << Min << " " << Max << "\n";
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<unsigned short> A, B;
	unsigned short a = 1, b = 1;
	while (a != 0 || b != 0)
	{
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}
	
	for (size_t i = 0; i < A.size() - 1; i++)
		cout << (B[i] % A[i] ? A[i] % B[i] ? "neither" : "multiple" : "factor") << endl;

	return 0;
}
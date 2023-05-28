#include <iostream>
#include <vector>

using namespace std;

int main()
{
	bool coords[100][100]{ 0, };
	unsigned short area = 0;
	unsigned short n;
	cin >> n;

	for (unsigned short i = 0; i < n; i++)
	{
		unsigned short min[2] = { 0, 0 };
		cin >> min[0];
		cin >> min[1];

		for (int y = min[1]; y < min[1] + 10; y++)
		{
			for (int x = min[0]; x < min[0] + 10; x++)
			{
				if (!coords[x][y])
				{
					coords[x][y] = true;
					area++;
				}
			}
		}
	}

	cout << area;

	return 0;
}
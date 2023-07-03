#include <iostream>

using namespace std;

unsigned char Gears[4];

void Rotate(int gear, int dir)
{
	if (dir == 1)
		Gears[gear] = (Gears[gear] >> 1) + (Gears[gear] & 0x01 ? 0x80 : 0);
	else
		Gears[gear] = (Gears[gear] << 1) + (Gears[gear] & 0x80 ? 0x01 : 0);
}

void RotateCenter(int gear, int dir)
{
	bool connected[3];
	for (int i = 0; i < 3; i++)
		connected[i] = (Gears[i] & 0x20 ? 1 : 0) ^ (Gears[i + 1] & 0x02 ? 1 : 0);

	Rotate(gear, dir);

	int left = gear - 1;
	int dl = dir;
	while (left >= 0 && connected[left])
		Rotate(left--, dl = -dl);

	int dr = dir;
	while (gear < 3 && connected[gear])
		Rotate(++gear, dr = -dr);
}

int main()
{
	for (unsigned char& gear : Gears)
	{
		char num[9];
		cin >> num;

		for (int j = 0; j < 8; j++)
			if (num[j] == '1')
				gear += 1 << (7 - j);
	}

	int K;
	cin >> K;
	while (K--)
	{
		int gear, dir;
		cin >> gear >> dir;
		RotateCenter(gear - 1, dir);
	}

	int score = 0;
	for (int i = 0; i < 4; i++)
		score += Gears[i] & 0x80 ? 1 << i : 0;

	cout << score << "\n";
	return 0;
}
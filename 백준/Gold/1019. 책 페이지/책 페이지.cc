#include <iostream>

using namespace std;

int Nums[10];

int main()
{
	int N;
	cin >> N;

	int n = N;
	for (int up = 1; n > 0; up *= 10)
	{
		int r = n % 10;		// 현재 단계 자리 숫자
		int q = n / 10;		// 현재 자리 보다 앞 숫자들

		int temp = q * up;
		for (int i = 0; i < r; i++)			// 1) d < r인 숫자 갯수
			Nums[i] += temp + up;
		Nums[0] -= up;						// 2) 앞자리가 0인 숫자 제외

		Nums[r] += temp + (N % up + 1);		// 3) d = r인 숫자 갯수

		for (int i = r + 1; i < 10; i++)	// 4) r < d <= 9인 숫자 갯수
			Nums[i] += temp;

		n /= 10;
	}

	for (int i : Nums)
		cout << i << " ";
	cout << "\n";
	return 0;
}
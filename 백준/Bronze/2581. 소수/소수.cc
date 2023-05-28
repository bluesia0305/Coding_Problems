#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int M, N;
	cin >> M;
	cin >> N;

	vector<int> primes;
	vector<bool> sieve(N + 1);
	int sum_primes = 0;
	
	for (int i = 2; i <= N; i++)
	{
		if (!sieve[i])
		{
			sieve[i] = true;
			if (i >= M)
			{
				primes.push_back(i);
				sum_primes += i;
			}
		}
		
		for (int j = i; j <= N; j += i)
			sieve[j] = true;
	}

	if (!primes.empty())
		cout << sum_primes << endl << primes[0] << endl;
	else
		cout << "-1" << endl;
	
	return 0;
}
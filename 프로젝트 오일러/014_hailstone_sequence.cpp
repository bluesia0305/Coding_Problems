// Problem #014: �鸸 ���Ϸ� �����ϴ� ��ڼ� �� ���� �� ������ ��ġ�� ����?

#include <iostream>
#include <ctime>
#include <map>

void print_hailstone(long long num)
{	
	long long i = 1;
	while (true)
	{
		printf("%lld ", num);
		if (num <= 1) break;
		else
		{
			printf("-> ");
			if (!(num % 2)) num = num / 2;
			else num = 3 * num + 1;
			++i;
		}
	}
	printf("\n");
}

int main()
{
	clock_t start, end;
	start = clock();

	const int N = 1000000;

	// key: ����, value: ��ڼ��� ���� �� �� pair�� ���� map container�� �̿�.
	std::map<long long, int> hailstone_numbers;
	hailstone_numbers.insert(std::pair<long long, int>(1, 1));

	for (long long i = 1; i <= N; ++i)
	{
		long long num = i;
		// 0���� �����ؼ�, Ư�� ������ ������ ������ order�� ���������ؾ� ����� ����.
		int hailstone_order = 0;
		if (!(i % 100000)) printf("�ڿ��� %lld �� ��ڼ��� Ž�� ��...\n", num);
		while (true)
		{
			if (num == 1)
			{
				++hailstone_order;
				break;
			}
			else
			{
				// �� �κ��� ���� ���࿡ �ٽ�(�̹� ���� ���ڿ� ���� ���� ����)
				auto iter = hailstone_numbers.find(num);
				if (iter != hailstone_numbers.end())
				{
					hailstone_order += iter->second;
					break;
				}
				else
				{
					if (!(num % 2)) num /= 2;
					else num = 3 * num + 1;
					++hailstone_order;
				}
			}
		}
		hailstone_numbers.insert(std::pair<long long, int>(i, hailstone_order));
	}

	long long max_hailstone_num = 1;
	int max_hailstone_order = 1;
	auto iter = hailstone_numbers.begin();
	for (; iter != hailstone_numbers.end(); ++iter)
	{
		if (iter->second > max_hailstone_order)
		{
			max_hailstone_num = iter->first;
			max_hailstone_order = iter->second;
		}
	}

	printf("��: %lld (��ڼ��� ���� %i ȸ)\n", max_hailstone_num, max_hailstone_order);
	print_hailstone(max_hailstone_num);

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
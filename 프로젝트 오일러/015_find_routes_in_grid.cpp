// Problem #015: 20��20 ������ �»�ܿ��� ���ϴ����� ���� ����� ��

#include <iostream>
#include <ctime>
#include <vector>

int main()
{
	clock_t start, end;
	start = clock();

	// 2x2 ���� ��� ��?
	//		1
	//	  1   1
	//  1   2   1
	//    3   3
	//      6
	
	// 3x3 ���� ����� ��?
	//        1
	//      1   1
	//    1   2   1
	//  1   3   3   1  <- nxn ������ ���, n+1 ���� ��(3C0 + 3C1 + 3C2 + 3C3)
	//    4   6   4
	//     10   10
	//       20

	std::vector<long long> vector;
	vector.push_back(1);
	vector.push_back(1);
	
	for (int i = 2; i <= 20; ++i)
	{
		std::vector<long long> vector_next;
		vector_next.push_back(1);
		for (int j = 0; j < vector.size() - 1; ++j)
			vector_next.push_back(vector[j] + vector[j + 1]);
		
		vector_next.push_back(1);
		vector = vector_next;
	}
	
	while (vector.size() > 1)
	{
		std::vector<long long> vector_next;
		for (int i = 0; i < vector.size() - 1; ++i)
			vector_next.push_back(vector[i] + vector[i + 1]);
		
		vector = vector_next;
	}

	// ��� �׳� 40! / 20! * 20! �� ����ϸ� ��... (�ߺ����� ����)
	// �ߺ����� ����(permutations of multisets)
	// : �ߺ����� M�� �� ������ ������ m1, m2, ..., mk�̰� �� ���� n�� ��
	//   ������ ���� = n! / (m1! * m2! * ... * mk!).
	printf("��: %lld\n", vector[0]);	

	end = clock();
	printf("����ð�: %.3llf ms\n", (double)(end - start));
	return 0;
}
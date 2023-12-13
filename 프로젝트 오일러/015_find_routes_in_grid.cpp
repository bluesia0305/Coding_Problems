// Problem #015: 20×20 격자의 좌상단에서 우하단으로 가는 경로의 수

#include <iostream>
#include <ctime>
#include <vector>

int main()
{
	clock_t start, end;
	start = clock();

	// 2x2 격자 경로 수?
	//		1
	//	  1   1
	//  1   2   1
	//    3   3
	//      6
	
	// 3x3 격자 경로의 수?
	//        1
	//      1   1
	//    1   2   1
	//  1   3   3   1  <- nxn 격자의 경우, n+1 개의 항(3C0 + 3C1 + 3C2 + 3C3)
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

	// 사실 그냥 40! / 20! * 20! 을 계산하면 됨... (중복집합 순열)
	// 중복집합 순열(permutations of multisets)
	// : 중복집합 M의 각 원소의 개수가 m1, m2, ..., mk이고 그 합이 n일 때
	//   순열의 개수 = n! / (m1! * m2! * ... * mk!).
	printf("답: %lld\n", vector[0]);	

	end = clock();
	printf("실행시간: %.3llf ms\n", (double)(end - start));
	return 0;
}
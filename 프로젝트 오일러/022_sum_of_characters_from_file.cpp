// Problem #022: 영문 이름 점수 합계 구하기

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#define SEPARATOR ','

int main()
{
	clock_t start, end;
	start = clock();
	
	std::string in_file = "Problem021-040/Problem022/names.txt";
	std::ifstream fin(in_file);

	fin.seekg(0, fin.end);
	int size = static_cast<int>(fin.tellg());
	//printf("names.txt: %i Byte.\n", size);

	fin.seekg(0, fin.beg);
	std::string data;
	fin >> data;
	fin.close();

	std::istringstream iss(data);
	std::string strBuffer;
	std::map<std::string, char> nameList;
	while (std::getline(iss, strBuffer, SEPARATOR))
	{ nameList.insert(std::pair<std::string, char>(strBuffer, 0)); }

	long long sum = 0;
	auto iter = nameList.begin();
	int n = 1;
	for (; iter != nameList.end(); ++iter)
	{
		//printf("%4i: ", n);
		//printf("%-15s", iter->first.c_str());
		int score = 0;
		for (int i = 0; i < iter->first.length(); ++i)
		{
			if (iter->first[i] != '\"')
			{ score += (int)((char)(iter->first[i]) - 'A' + 1); }
		}
		score *= n++;
		//printf("%d\n", score);
		sum += score;
	}
	printf("답: %lld\n", sum);
	
	end = clock();
	printf("실행시간: %.3lf ms\n", (double)(end - start));
	return 0;
}
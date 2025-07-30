#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int a, int b, int c, int d)
{
    map<int, int> numbers;
    numbers[a]++;
    numbers[b]++;
    numbers[c]++;
    numbers[d]++;
    
    switch (numbers.size())
    {
        case 1:
        {
            return 1111 * a;
        }
        case 2:
        {
            int p = numbers.begin()->first;
            int q = numbers.rbegin()->first;
            if (numbers.begin()->second == 2)
                return (p + q) * (q - p);
            else if (numbers[p] == 3)
                return (10 * p + q) * (10 * p + q);
            else
                return (10 * q + p) * (10 * q + p);
        }
        case 3:
        {
            int prod = 1;
            for (pair<int, int> elem : numbers)
                if (elem.second == 1)
                    prod *= elem.first;
            return prod;
        }
        case 4:
        {
            return numbers.begin()->first;
        }
    }
}
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial)
{
    int answer = 0;
    istringstream ss(binomial);
    int term1, term2;
    string op;
    ss >> term1 >> op >> term2;
    if (op == "+")
        return term1 + term2;
    else if (op == "-")
        return term1 - term2;
    else
        return term1 * term2;
}
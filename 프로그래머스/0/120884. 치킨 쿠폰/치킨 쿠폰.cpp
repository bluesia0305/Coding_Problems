#include <string>
#include <vector>

using namespace std;

int solution(int chicken)
{
    int coupons = 0;
    int answer = 0;
    while (chicken)
    {
        coupons += chicken;
        chicken = coupons / 10;
        coupons %= 10;
        answer += chicken;
    }
    
    return answer;
}
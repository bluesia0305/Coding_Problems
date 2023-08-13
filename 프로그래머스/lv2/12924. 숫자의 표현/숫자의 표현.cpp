int solution(int n)
{
    int answer = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        int sum = 0, j = i;
        while (sum < n)
            sum += j++;
        
        if (sum == n)
            answer++;
    }
    return answer;
}
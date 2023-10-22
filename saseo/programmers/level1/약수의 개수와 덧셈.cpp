int getDivisorNum(int n);

int solution(int left, int right) {
    int answer = 0;
    while (left <= right)
    {
        int divisor = getDivisorNum(left);
        answer = (divisor % 2) ? answer - left : answer + left;
        left++;
    }
    return answer;
}

int getDivisorNum(int n)
{
    int ret  = 0;
    
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
            ret++;
        if (i * i == n)
            return ret * 2 - 1;
    }
    
    return ret * 2;
}
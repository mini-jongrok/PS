long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long total = price;
    if (count % 2 == 0)
    {
        total *= (count / 2) * (count + 1);
    } else {
        total *= ((count + 1) / 2) * count;
    }
    
    if (money >= total)
        answer = 0;
    else
        answer = total - money;

    return answer;
}
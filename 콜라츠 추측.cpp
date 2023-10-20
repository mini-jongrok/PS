#include <vector>

using namespace std;
int solution(long long &num, int &loop);
int solution(int num) {
    int loop = 0;
    long long tmp = num;
    int answer = solution(tmp, loop);
    return answer;
}

int solution(long long &num, int &loop)
{   
    if (loop >= 500)
        return -1;
    
    if (num == 1)
        return loop;
  
    if (num % 2 == 0)
        num /= 2;
    else
        num = num * 3 + 1;
    loop++;
    return (solution(num, loop));
}

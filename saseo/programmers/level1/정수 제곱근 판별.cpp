
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = -1;

    int64_t start = 1;
    int64_t end = n;

    while (start <= end)
    {
        u_int64_t mid = (start + end) / 2;
        u_int64_t sq = mid * mid;
        if (sq == n)
            return (mid + 1) * (mid + 1);

        if (sq > n)
            end = mid - 1;
        else if (sq < n)
            start = mid + 1;
    }
    return answer;
}

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int tmp = x;
    long long sum = 0;
    while (tmp)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
    if (x % sum)
        answer = false;
    return answer;
}

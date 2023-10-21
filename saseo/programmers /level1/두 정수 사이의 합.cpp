#include <vector>
#include <iostream>

using namespace std;

long long   sigma(int a, int b);

long long solution(int a, int b) {
    int min = (a > b) ? b : a;
    int max = (a > b) ? a : b;
    
    if (a == b)
        return a;
    return sigma(min, max);
}

long long   sigma(int a, int b)
{
    long long ans = a + b;
    long long len = (b - a + 1);
    
    if (ans % 2 == 0)
        ans = (ans / 2) * len;
    else
        ans = (len / 2) * ans;
    return ans;
}

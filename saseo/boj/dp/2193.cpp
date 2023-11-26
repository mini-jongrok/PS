#include<iostream>
#include<cstring>

using namespace std;
long long cache[100];
long long dp(int n);
int main()
{
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    cout << dp(n) << "\n";
    return 0;
}

long long dp(int n)
{
    if (n < 2) return 1;
    long long & ret = cache[n];
    if(ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= n - 2; ++i)
        ret += dp(i);
    return ret;
}

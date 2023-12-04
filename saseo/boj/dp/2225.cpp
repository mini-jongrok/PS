#include <iostream>
#include <cstring>
using namespace std;
int n, k;
int mod = 1000000000;
long long cache[202][202];
long long dp(int n, int k);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	cout << dp(n, k) << "\n";
	return 0;
}

long long dp(int n, int k)
{
	if (k == 1) return 1;
	long long & ret = cache[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n; ++i)
		ret += dp(n - i, k - 1) % mod;
	ret %= mod;
	return ret;
}

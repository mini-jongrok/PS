#include <iostream>
#include <cstring>
using namespace std;
int n;
int mod = 9901;
int cache[100005];
int dp(int n);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cache[1] = 3;
	cache[2] = 7;
	cout << dp(n) << "\n";
	return 0;
}

int dp(int n)
{
	if (n == 0) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = (dp(n - 2) + (2 * dp(n - 1))) % mod;
	return ret;
}

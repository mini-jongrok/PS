#include <iostream>
#include <cstring>

using namespace std;

int cache[1001];
int mod = 10007;

int dp(int n);
int main()
{
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	cout << dp(n) << "\n";
	return 0;
}

int dp(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 3;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = dp(n - 1) + (2 * dp(n - 2)) % mod;
	return ret;
}

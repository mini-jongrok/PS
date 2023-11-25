#include <iostream>
#include <cstring>

using namespace std;
long long dp(long long *cache, int n);
int main()
{
	int n;
	cin >> n;
	long long cache[100];
	memset(cache, -1, sizeof(cache));
	cout << dp(cache, n) << "\n";
	return 0;
}

long long dp(long long *cache, int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	long long& ret = cache[n];
	if (ret != -1) return ret;

	ret = dp(cache, n - 2) + dp(cache, n - 1);
	return ret;
}

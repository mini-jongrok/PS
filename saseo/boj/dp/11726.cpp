#include <iostream>
#include <cstring>

using namespace std;
int cache[1001];
int mod = 10007;

int dp(int n);
int main()
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << dp(n) << "\n";
	return 0;
}

int dp(int n)
{
	//base 1->1, 2->2
	if (n < 3) return n;

	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = (dp(n - 1) + dp(n - 2)) % mod;
	return ret;
}

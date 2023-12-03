#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[40][40][40];
int dp(int, int, int);
int main()
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << dp(0, 0, 0) << "\n";
	return 0;
}

int dp(int b, int m, int t)
{
	if (b > n || m > n || t > n) return 0;
	if (b == n && m == n && t == n) return 1;

	int& ret = cache[b][m][t];
	if (ret != -1) return ret;

	// case 1)
	if (b == m && m == t)
		ret = dp(b, m + 1, t + 1) + dp(b + 1, m + 1, t) + dp(b + 2, m + 2, t + 2);
	// case 2)
	if (t == m && b == m - 1)
		ret = dp(b + 2, m + 1, t + 1) + dp(b + 2, m + 2, t + 2);
	// case 3)
	if (b == m && t == m - 1)
		ret = dp(b + 1, m + 1, t + 2) + dp(b + 2, m + 2, t + 2);
	return ret;
}

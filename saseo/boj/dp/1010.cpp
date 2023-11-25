#include <iostream>
#include <cstring>

using namespace std;

int cache[31][31];

int dp(int n, int m);

int main()
{
	memset(cache, -1, sizeof(cache));
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> m;
		cout << dp(n, m) << "\n";
	}
	return 0;
}

int dp(int n, int m)
{
	if (n == m) return 1;
	if (n == 1) return m;
	int & ret = cache[n][m];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = m - 1; i >= n -1; --i)
		ret += dp(n - 1, i);
	return ret;
}

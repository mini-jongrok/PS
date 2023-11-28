#include <iostream>
#include <cstring>
using namespace std;

int cache[1001];
int pack[1001];
int n;

int dp(int n);
int main()
{
	cin >> n;
	for (int i = 1; i < n + 1; ++i)
		cin >> pack[i];
	memset(cache, -1, sizeof(cache));
	cout << dp(n) << "\n";
	return 0;
}

int dp(int n)
{
	if (n <= 0) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= n; ++i)
		ret = max(ret, pack[i] + dp(n - i));
	return ret;
}

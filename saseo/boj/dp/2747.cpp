#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[100];
int dp(int n);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cache[0] = 0;
	cache[1] = 1;
	cout << dp(n) << "\n";
	return 0;
}

int dp(int n)
{
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = dp(n - 2) + dp(n - 1);
	return ret;
}

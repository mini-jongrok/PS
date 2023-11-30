#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[1002][11];
int dp(int i, int start);
int main()
{
	memset(cache, -1, sizeof(cache));
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << dp(1, 0) << "\n";
	return 0;
}

int dp(int i, int start)
{
	if (i == n) return (10 - start);

	int & ret = cache[i][start];
	if (ret != -1) return ret;

	ret = 0;
	for (int j = start; j < 10; ++j)
		ret += dp(i + 1, j);
	ret %= 10007;
	return ret;
}

#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int candies[1010][1010];
int cache[1010][1010];
void input();
int dp(int i, int j);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	input();
	cache[n][m] = candies[n][m];
	cout << dp(1, 1) << "\n";
	return 0;
}

int dp(int i, int j)
{
	if (i > n || j > m) return 0;
	int & ret = cache[i][j];
	if (ret != -1) return ret;
	ret = candies[i][j];
	int tmp = max(dp(i + 1, j), dp(i, j + 1));
	tmp = max(tmp, dp(i + 1, j + 1));
	return ret = ret + tmp;
}

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> candies[i][j];
}
